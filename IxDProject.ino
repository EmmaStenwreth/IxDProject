#include <DFRobotDFPlayerMini.h>
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#include <FastLED.h>

#define LED1 3
#define LED1_COUNT 4
#define BRIGHTNESS 5

#define LED2 0
#define LED2_COUNT 8


CRGB leds[LED1_COUNT];

CRGB leds2[LED2_COUNT];

byte r,g,b;
float brightness;

int vibration1 = 2;

void setup() {
  // put your setup code here, to run once:

  FastLED.addLeds<NEOPIXEL, LED1>(leds, LED1_COUNT);
  FastLED.addLeds<NEOPIXEL, LED2>(leds2, LED2_COUNT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(vibration1, OUTPUT);
  //analogWrite(vibration1, 0);// This code makes it vibrate all the time :(

  Serial1.begin(9600);
  Serial.begin(115200);

    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
    
    if (!myDFPlayer.begin(Serial1)) {  //Use softwareSerial to communicate with mp3.
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1.Please recheck the connection!"));
      Serial.println(F("2.Please insert the SD card!"));
      while(true);
    }
    Serial.println(F("DFPlayer Mini online."));

  /*playSong();
  delay(10000);
  stopSong();*/

}

void loop() {
  // put your main code here, to run repeatedly:

  //digitalWrite(vibration1, HIGH); //vibrate
  //delay(1000);  // delay one second
  //digitalWrite(vibration1, LOW);  //stop vibrating
  //delay(1000); 

  //delay(500000);
  //vibrate();
  playSong();

}

void playSong() {
  FastLED.clear();
  FastLED.show();

  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3
  delay(588*7);

  FastLED.setBrightness(BRIGHTNESS);
    
  vibrateLow();  
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  fill_solid(leds2, LED2_COUNT, CRGB::Red);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationAndLedDelay();

  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationAndLedDelay();
  
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationAndLedDelay();
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationAndLedDelay();
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationAndLedDelay();
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationAndLedDelay();
  vibrateLow();

  stopSong();
  
  
}

void vibrateHigh() {
  digitalWrite(vibration1, HIGH); //vibrate 
}

void vibrateLow() {
  digitalWrite(vibration1, LOW); //dont vibrate
}

void vibrationAndLedDelay() {
  FastLED.delay(588);
  vibrateHigh();
  FastLED.delay(588);
  vibrateLow();
}

void stopSong() {
  myDFPlayer.stop();
}
