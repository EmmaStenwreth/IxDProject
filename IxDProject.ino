#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

#define LED_PIN 3
#define LED_COUNT 4

CRGB leds[LED_COUNT];

byte r,g,b;
float brightness;

int motorPin = 2; // motor transistor connected to pin D2

void setup() {
  // put your setup code here, to run once:

  //pinMode(motorPin, OUTPUT);

  //Serial.begin(9600);

 Serial.begin(9600);
  // init the LED object
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LED_COUNT);
  // set random seed
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:

   // loop over the NUM_LEDS
  for (int cur = 0; cur < LED_COUNT; cur++) {
    brightness = 50.0 / pow(2, cur);
    FastLED.setBrightness(brightness); // range: 0-255
    r = random(150, 200);
    g = random(100, 150);
    b = random(0, 50);
    //set the value to the led AND turn on
    leds[cur] = CRGB(r, g, b); FastLED.show();
    FastLED.delay(200);
    // turn off previous
    leds[cur] = CRGB::Black; FastLED.show();
    Serial.println(cur, DEC);
  }
  
  //digitalWrite(motorPin, HIGH);
  //delay(1000);
  //digitalWrite(motorPin, LOW);
  //delay(1000);
}
