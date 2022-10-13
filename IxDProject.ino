#include <DFRobotDFPlayerMini.h>
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#include <FastLED.h>

#define LED1 1
#define LED1_COUNT 4
#define BRIGHTNESS 5

#define LED2 2
#define LED2_COUNT 6


CRGB leds[LED1_COUNT];

CRGB leds2[LED2_COUNT];

byte r,g,b;
float brightness;

int vibration1 = A1;
int vibration2 = A2;
int vibration3 = A3;
int vibration4 = A4;

void setup() {
  // put your setup code here, to run once:

  FastLED.addLeds<NEOPIXEL, LED1>(leds, LED1_COUNT);
  FastLED.addLeds<NEOPIXEL, LED2>(leds2, LED2_COUNT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(vibration1, OUTPUT);
  pinMode(vibration2, OUTPUT);
  //analogWrite(vibration1, 0);// This code makes it vibrate all the time :(

  Serial1.begin(9600);
  //Serial.begin(115200);
  Serial.begin(9600); // GD <2022-10-11 Tue 18:09>

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
    
  //vibrateLow();  
  //fill_solid(leds, LED1_COUNT, CRGB::Red);
  //fill_solid(leds2, LED2_COUNT, CRGB::Red);
  right();
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  vibrationUpAndLedDelay();

  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  vibrationUpAndLedDelay();
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  vibrationUpAndLedDelay();
  
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationUpAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationUpAndLedDelay();
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationUpAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationUpAndLedDelay();
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationUpAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationUpAndLedDelay();
  leds[0] = CRGB:: Yellow;
  leds[1] = CRGB:: Red;
  leds[2] = CRGB:: Green;
  leds[3] = CRGB:: Blue;
  vibrationUpAndLedDelay();
  leds[0] = CRGB:: Blue;
  leds[1] = CRGB:: Green;
  leds[2] = CRGB:: Red;
  leds[3] = CRGB:: Yellow;
  vibrationUpAndLedDelay();

  stopSong();
  
  
}

void vibrationUpAndLedDelay() {
  digitalWrite(vibration2, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration1, HIGH); 
  digitalWrite(vibration2, LOW);
  FastLED.delay(588);
  digitalWrite(vibration1, LOW);
}

void vibrationDownAndLedDelay() {
  digitalWrite(vibration4, HIGH);
  digitalWrite(vibration3, HIGH);  
  FastLED.delay(588);
  digitalWrite(vibration3, LOW);
  digitalWrite(vibration4, LOW);
  FastLED.delay(588);
}

void vibrationLeftAndLedDelay() {
  digitalWrite(vibration2, HIGH);
  digitalWrite(vibration3, HIGH);  
  FastLED.delay(588);
  digitalWrite(vibration2, LOW);
  digitalWrite(vibration3, LOW);
  FastLED.delay(588);
}

void vibrationRightAndLedDelay() {
  digitalWrite(vibration4, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration1, HIGH); 
  digitalWrite(vibration4, LOW);
  FastLED.delay(588);
  digitalWrite(vibration1, LOW);
}

void vibrationLeftUpAndLedDelay() {
  digitalWrite(vibration2, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration2, LOW);
  FastLED.delay(588);
}

void vibrationLeftDownAndLedDelay() {
  digitalWrite(vibration3, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration3, LOW);
  FastLED.delay(588);
}

void vibrationRightUpAndLedDelay() {
  FastLED.delay(588);
  digitalWrite(vibration1, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration1, LOW);
}

void vibrationRightDownAndLedDelay() {
  digitalWrite(vibration4, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration4, LOW);
  FastLED.delay(588);
}


//LED-Strip combinations
void leftUp() {
  fill_solid(leds, LED1_COUNT, CRGB::Green);
}

void leftDown() {
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
}

void rightUp() {
  fill_solid(leds2, LED2_COUNT, CRGB::Orange);
}

void rightDown() {
  fill_solid(leds, LED1_COUNT, CRGB::Pink);
}

void up() {
  fill_solid(leds, LED1_COUNT, CRGB::Yellow);
  fill_solid(leds2, LED2_COUNT, CRGB::Yellow);
}

void down() {
  fill_solid(leds, LED1_COUNT, CRGB::Blue);
  fill_solid(leds2, LED2_COUNT, CRGB::Blue);
}

void left() {
  fill_solid(leds, LED1_COUNT, CRGB::Green);
  fill_solid(leds2, LED2_COUNT, CRGB::Green);
}

void right() {
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  fill_solid(leds2, LED2_COUNT, CRGB::Red);
}

void stopSong() {
  myDFPlayer.stop();
}
