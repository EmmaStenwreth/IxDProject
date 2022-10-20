#include <DFRobotDFPlayerMini.h>
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#include <FastLED.h>

#define LED1 1
#define LED1_COUNT 6
#define BRIGHTNESS 5

#define LED2 2
#define LED2_COUNT 6

#define LED3 3
#define LED3_COUNT 6

#define LED4 4
#define LED4_COUNT 6

#define LED5 5
#define LED5_COUNT 14


CRGB leds1[LED1_COUNT];
CRGB leds2[LED2_COUNT];
CRGB leds3[LED3_COUNT];
CRGB leds4[LED4_COUNT];
CRGB ledsBall[LED5_COUNT];

byte r,g,b;
float brightness;

int vibration1 = A1; //Right up
int vibration2 = A2; // left up
int vibration3 = A3; // left Down
int vibration4 = A4; // right down

void setup() {
  // put your setup code here, to run once:

  FastLED.addLeds<NEOPIXEL, LED1>(leds1, LED1_COUNT);
  FastLED.addLeds<NEOPIXEL, LED2>(leds2, LED2_COUNT);
  FastLED.addLeds<NEOPIXEL, LED3>(leds3, LED3_COUNT);
  FastLED.addLeds<NEOPIXEL, LED4>(leds4, LED4_COUNT);
  FastLED.addLeds<NEOPIXEL, LED5>(ledsBall, LED5_COUNT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  pinMode(vibration1, OUTPUT);
  pinMode(vibration2, OUTPUT);
  pinMode(vibration3, OUTPUT);
  pinMode(vibration4, OUTPUT);
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
  
  // Sequence 1
  right();
  vibrationRightAndLedDelay();
  off();
  left();
  vibrationLeftAndLedDelay();
  off();
  right();
  vibrationRightAndLedDelay();
  off();
  left();
  vibrationLeftAndLedDelay();
  off();
  right();
  vibrationRightAndLedDelay();
  off();
  left();
  vibrationLeftAndLedDelay();
  off();
  right();
  vibrationRightAndLedDelay();
  off();
  left();
  vibrationLeftAndLedDelay();
  off();
  
  // Sequence 2
  up();
  vibrationUpAndLedDelay();
  off();
  down();
  vibrationDownAndLedDelay();
  off();
  up();
  vibrationUpAndLedDelay();
  off();
  down();
  vibrationDownAndLedDelay();
  off();
  up();
  vibrationUpAndLedDelay();
  off();
  down();
  vibrationDownAndLedDelay();
  off();
  up();
  vibrationUpAndLedDelay();
  off();
  down();
  vibrationDownAndLedDelay();
  off();

  // Sequence 3
  rotateClockwise();
  vibrationAllAndDelay();
  off();
  rotateCounterClockwise();
  vibrationAllAndDelay();
  off();
  rotateClockwise();
  vibrationAllAndDelay();
  off();
  rotateCounterClockwise();
  vibrationAllAndDelay();
  off();

  stopSong();
  
  
}

// Vibration motors ----------------------------------------------------------------------

// Vibration movement UP
void vibrationUpAndLedDelay() {
  digitalWrite(vibration2, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration1, HIGH); 
  digitalWrite(vibration2, LOW);
  FastLED.delay(588);
  digitalWrite(vibration1, LOW);
}
// Vibration movement DOWN
void vibrationDownAndLedDelay() {
  digitalWrite(vibration4, HIGH);
  digitalWrite(vibration3, HIGH);  
  FastLED.delay(588);
  digitalWrite(vibration3, LOW);
  digitalWrite(vibration4, LOW);
  FastLED.delay(588);
}
// Vibration movement LEFT
void vibrationLeftAndLedDelay() {
  digitalWrite(vibration2, HIGH);
  digitalWrite(vibration3, HIGH);  
  FastLED.delay(588);
  digitalWrite(vibration2, LOW);
  digitalWrite(vibration3, LOW);
  FastLED.delay(588);
}
// Vibration movement RIGHT
void vibrationRightAndLedDelay() {
  digitalWrite(vibration4, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration1, HIGH); 
  digitalWrite(vibration4, LOW);
  FastLED.delay(588);
  digitalWrite(vibration1, LOW);
}
// Vibration movememnt LEFT UP
void vibrationLeftUpAndLedDelay() {
  digitalWrite(vibration2, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration2, LOW);
  FastLED.delay(588);
}
// Vibration movement LEFT DOWN
void vibrationLeftDownAndLedDelay() {
  digitalWrite(vibration3, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration3, LOW);
  FastLED.delay(588);
}
// Vibration movement RIGHT UP
void vibrationRightUpAndLedDelay() {
  FastLED.delay(588);
  digitalWrite(vibration1, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration1, LOW);
}
// Vibration movement DOWN RIGHT
void vibrationRightDownAndLedDelay() {
  digitalWrite(vibration4, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration4, LOW);
  FastLED.delay(588);
}
// Vibration all
void vibrationAllAndDelay() {
  digitalWrite(vibration1, HIGH);
  digitalWrite(vibration2, HIGH);
  digitalWrite(vibration3, HIGH);
  digitalWrite(vibration4, HIGH); 
  FastLED.delay(588);
  digitalWrite(vibration1, LOW);
  digitalWrite(vibration2, LOW);
  digitalWrite(vibration3, LOW);
  digitalWrite(vibration4, LOW);
  FastLED.delay(588);
}

//LED-Strip combinations ----------------------------------------------------------------------

// Turn off all lights.
void off() {
  FastLED.clear();
}

// Diagonal moves ------------------
void leftUp() {
  fill_solid(leds2, LED2_COUNT, CRGB::Green);
  ballLeftUp();
}

void leftDown() {
  fill_solid(leds3, LED3_COUNT, CRGB::Blue);
  ballLeftDown();
}

void rightUp() {
  fill_solid(leds1, LED1_COUNT, CRGB::Orange);
  ballRightUp();
}

void rightDown() {
  fill_solid(leds4, LED4_COUNT, CRGB::Pink);
  ballRightDown();
}

// x/y-moves ------------------------
void up() {
  fill_solid(leds1, LED1_COUNT, CRGB::Yellow);
  fill_solid(leds2, LED2_COUNT, CRGB::Yellow);  
  ballUp();
}

void down() {
  fill_solid(leds3, LED3_COUNT, CRGB::Blue);
  fill_solid(leds4, LED4_COUNT, CRGB::Blue);
  ballDown();
}

void left() {
  fill_solid(leds2, LED2_COUNT, CRGB::Green);
  fill_solid(leds3, LED3_COUNT, CRGB::Green);
  ballLeft();
}

void right() {
  fill_solid(leds, LED1_COUNT, CRGB::Red);
  fill_solid(leds4, LED4_COUNT, CRGB::Red);
  ballRight();
}

// Whole ball white light
void ballAll() {
  fill_solid(ledsBall, LED5_COUNT, CRGB::AntiqueWhite);  
}

// Here is ball! 
void ballLeftUp() {
  for (int i = 6; i < 10; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Green;
  }
}

void ballLeftDown() {
  for (int i = 9; i < 14; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Blue;
  }
}

void ballRightUp() {
  for (int i = 3; i < 7; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Red;
  }
}

void ballRightDown() {
  for (int i = 0; i < 4; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Red;
  }
}

void ballUp() {
  for (int i = 3; i < 10; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Red;
  }
}

void ballDown() {
  for (int i = 0; i < 3; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Red;
  }
  for (int j = 9; j < 14; j++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[j] = CRGB::Red;
  }
}

void ballLeft() {
  for (int i = 6; i < 14; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Red;
  }
}

void ballRight() {
  for (int i = 0; i < 7; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Red;
  }
}

// Rotation moves ----------------------------------------------------
void rotateClockwise() {
  leftUp();
  ballLeftUp();
  rightUp();
  ballRightUp();
  rightDown();
  ballRightDown();
  leftDown();
  ballLeftDown();
}

void rotateCounterClockwise() {
  rightUp();
  ballRightUp();
  leftUp();
  ballLeftUp();
  leftDown();
  ballLeftDown();
  rightDown();
  ballRightDown();
}

void stopSong() {
  myDFPlayer.stop();
}

 /*
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
  */
