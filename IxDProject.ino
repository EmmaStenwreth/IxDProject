#include <FastLED.h>
// Library for Bluetooth connection
#include <ArduinoBLE.h>
BLEService newService("180A"); // creating the service

BLEUnsignedCharCharacteristic randomReading("2A58", BLERead | BLENotify); // creating the Analog Value characteristic
BLEByteCharacteristic switchChar("2A57", BLERead | BLEWrite); // creating the LED characteristic
BLEByteCharacteristic switchCharLED("2A59", BLERead | BLEWrite); // creating the LED-strip characteristic

// ledPin is for single led indicating bluetooth connection.
const int ledPin = 2;
long previousMillis = 0;

#define LED_PIN 3
#define LED_COUNT 4
#define BRIGHTNESS 5

CRGB leds[LED_COUNT];

byte r,g,b;
float brightness;

void setup() {
  // put your setup code here, to run once:

  //pinMode(motorPin, OUTPUT);

  // init the LED object
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LED_COUNT);
  // set random seed
  randomSeed(analogRead(0));

 Serial.begin(9600);

  while(!Serial);

  pinMode(LED_BUILTIN, OUTPUT); // initialize the built-in LED pin to indicate when a central is connected
  pinMode(ledPin, OUTPUT); // initialize the built-in LED pin to indicate when a central is connected

  //initialize ArduinoBLE library
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy failed!");
    while (1);
  }

  BLE.setLocalName("Great Ball of Fire"); //Setting a name that will appear when scanning for Bluetooth® devices
  BLE.setAdvertisedService(newService);

  newService.addCharacteristic(switchChar); //add characteristics to a service
  newService.addCharacteristic(switchCharLED);
  newService.addCharacteristic(randomReading);

  BLE.addService(newService);  // adding the service

  switchChar.writeValue(0); //set initial value for characteristics
  randomReading.writeValue(0);
  switchCharLED.writeValue(0);

  BLE.advertise(); //start advertising the service
  Serial.println("Bluetooth® device active, waiting for connections...");
}

void loop() {
  // put your main code here, to run repeatedly:

//  FastLED.setBrightness(BRIGHTNESS);
//  leds[0] = CRGB(0, 0, 255); 
//  leds[1] = CRGB(0, 255, 0);
//  leds[2] = CRGB(255, 0, 0);
//  leds[3] = CRGB(255, 255, 255);
//  FastLED.show();
//
//  for(int i = 0; i < LED_COUNT; i++){
//    leds[i] = CRGB::Black;
//    FastLED.show();
//  }

  BLEDevice central = BLE.central(); // wait for a Bluetooth® Low Energy central

  if (central) {  // if a central is connected to the peripheral
    Serial.print("Connected to central: ");

    Serial.println(central.address()); // print the central's BT address

    digitalWrite(LED_BUILTIN, HIGH); // turn on the LED to indicate the connection

    while (central.connected()) { // while the central is connected:
      long currentMillis = millis();

      if (currentMillis - previousMillis >= 200) {
        previousMillis = currentMillis;

        int randomValue = analogRead(A1);
        randomReading.writeValue(randomValue);

        if (switchChar.written()) {
          if (switchChar.value()) {   // any value other than 0
            Serial.println("LED on");
            digitalWrite(ledPin, HIGH);         // will turn the LED on
          } else {                              // a 0 value
            Serial.println(F("LED off"));
            digitalWrite(ledPin, LOW);          // will turn the LED off
          }
        }

        
          if (switchCharLED.value()) {   // any value other than 0
            Serial.println("LED-strip on");
            FastLED.setBrightness(BRIGHTNESS);
            FastLED.delay(1000);
            fill_solid(leds, LED_COUNT, CRGB::Blue);
            FastLED.delay(1000);
            fill_solid(leds, LED_COUNT, CRGB::Red);
            FastLED.delay(1000);
            fill_solid(leds, LED_COUNT, CRGB::Green);
            FastLED.delay(1000);
            fill_solid(leds, LED_COUNT, CRGB::Yellow);
          } else {                              // a 0 value
            Serial.println(F("LED-strip off"));
            fill_solid(leds, LED_COUNT, CRGB::White);
          }
        

      }
    }

    digitalWrite(LED_BUILTIN, LOW); // when the central disconnects, turn off the LED
    Serial.print("Disconnected from central: ");
    Serial.println(central.address());
  }

//   // loop over the NUM_LEDS
//  for (int cur = 0; cur < LED_COUNT; cur++) {
//    brightness = 50.0 / pow(2, cur);
//    FastLED.setBrightness(brightness); // range: 0-255
//    r = random(150, 200);
//    g = random(100, 150);
//    b = random(0, 50);
//    //set the value to the led AND turn on
//    leds[cur] = CRGB(r, g, b); FastLED.show();
//    FastLED.delay(200);
//    // turn off previous
//    leds[cur] = CRGB::Black; FastLED.show();
//    Serial.println(cur, DEC);
//  }
  
  //digitalWrite(motorPin, HIGH);
  //delay(1000);
  //digitalWrite(motorPin, LOW);
  //delay(1000);
}
