#include <DFRobotDFPlayerMini.h>
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#include <FastLED.h>

#define LED1 3
#define LED1_COUNT 4
#define BRIGHTNESS 5

CRGB leds[LED1_COUNT];

byte r,g,b;
float brightness;

int vibration1 = 2;

void setup() {
  // put your setup code here, to run once:

  FastLED.addLeds<NEOPIXEL, LED1>(leds, LED1_COUNT);

  pinMode(LED1, OUTPUT);

  pinMode(vibration1, OUTPUT);
  analogWrite(vibration1, 0);

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

  digitalWrite(vibration1, HIGH); //vibrate
  delay(1000);  // delay one second
  digitalWrite(vibration1, LOW);  //stop vibrating
  delay(1000); 

  delay(500000);

  //playSong();

}

void playSong() {

  FastLED.clear();
  FastLED.show();

  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3

  delay(588*7);

  FastLED.setBrightness(BRIGHTNESS);
    
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  FastLED.delay(588*2);
  digitalWrite(vibration1, HIGH);
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  FastLED.delay(588*2);
  digitalWrite(vibration1, LOW);
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  FastLED.delay(588*2);

  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  FastLED.delay(588*2);
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  FastLED.delay(588*2);
  
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  FastLED.delay(588*2);
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  FastLED.delay(588*2);
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  FastLED.delay(588*2);
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  FastLED.delay(588*2);
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  FastLED.delay(588*2);
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  FastLED.delay(588*2);
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  FastLED.delay(588*2);
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  FastLED.delay(588*2);

  stopSong();
  
  
}

void stopSong() {
  myDFPlayer.stop();
}
