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

#define BUTTON 6
int buttonState = 0; 

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

  pinMode(BUTTON, INPUT);

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

  buttonState = digitalRead(BUTTON);
  // Can only start program, not stop it. 
  // To implement that, look at this: https://littlebirdelectronics.com.au/guides/49/use-a-push-button-with-arduino
  if(buttonState == HIGH) playSong();
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
  leftUp();
  vibrationLeftUpAndLedDelay();
  off();
  rightDown();
  vibrationRightDownAndLedDelay();
  off();
  rightUp();
  vibrationRightUpAndLedDelay();
  off();
  leftDown();
  vibrationLeftDownAndLedDelay();
  off();
  leftUp();
  vibrationLeftUpAndLedDelay();
  off();
  rightDown();
  vibrationRightDownAndLedDelay();
  off();
  rightUp();
  vibrationRightUpAndLedDelay();
  off();
  leftDown();
  vibrationLeftDownAndLedDelay();
  off();

  // Sequence 4
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
  up();
  vibrationUpAndLedDelay();
  off();
  down();
  vibrationDownAndLedDelay();
  off();
  up();
  vibrationUpAndLedDelay();
  off();
  powerPose();
  vibrationAllAndDelay();
  off();

  // Sequence 5
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

  //Sequence 6
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

  // Sequence 7
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

  // Sequence 8
  up();
  vibrationUpAndLedDelay();
  off();
  // The up motion should NOT notify to move to the middle this time so the player stays up.  
  //-------------------------
  shakira();
  vibrationAllAndLedDelay();
  off();
  //-------------------------
  rightUp();
  vibrationRightUpAndLedDelay();
  off();
  leftDown();
  vibrationLeftDownAndLedDelay();
  off();
  leftUp();
  vibrationLeftUpAndLedDelay();
  off();
  rightDown();
  vibrationRightDownAndLedDelay();
  off();
  rightUp();
  vibrationRightUpAndLedDelay();
  off();
  leftDown();
  vibrationLeftDownAndLedDelay();
  off();

// Sequence 9
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
  up();
  vibrationUpAndLedDelay();
  off();
  down();
  vibrationDownAndLedDelay();
  off();
  up();
  vibrationUpAndLedDelay();
  off();
  powerPose();
  vibrationAllAndDelay();
  off();

  stopSong();
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
