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

// Here is ball! -------------------------
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

// Rotation shakira move ball
void ballLeftUpYellow() {
  for (int i = 6; i < 10; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Yellow;
  }
}

void clearLeftUp(){
  for(int i = 6; i < 10; i++){
    ledsBall[i].clear();
  }
}

void ballLeftDownYellow() {
  for (int i = 9; i < 14; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Yellow;
  }
}

void clearLeftDown(){
  for(int i = 9; i < 14; i++){
    ledsBall[i].clear();
  }
}

void ballRightUpYellow() {
  for (int i = 3; i < 7; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Yellow;
  }
}

void clearRightUp(){
  for(int i = 3; i < 7; i++){
    ledsBall[i].clear();
  }
}

void ballRightDownYellow() {
  for (int i = 0; i < 4; i++) { //Change the values of i = 0 and LED5_COUNT to the leds we want to go to 
    ledsBall[i] = CRGB::Yellow;
  }
}

void clearRightDown(){
  for(int i = 0; i < 4; i++){
    ledsBall[i].clear();
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

// Power pose! -------------------------------------
void powerPose() {
  fill_solid(leds1, LED1_COUNT, CRGB::Pink);
  fill_solid(leds2, LED2_COUNT, CRGB::Pink);
  fill_solid(leds3, LED3_COUNT, CRGB::Pink);
  fill_solid(leds4, LED4_COUNT, CRGB::Pink);
  fill_solid(leds5, LED5_COUNT, CRGB::Pink);
  FastLED.delay(588/4);
  off();
  fill_solid(leds1, LED1_COUNT, CRGB::Pink);
  fill_solid(leds2, LED2_COUNT, CRGB::Pink);
  fill_solid(leds3, LED3_COUNT, CRGB::Pink);
  fill_solid(leds4, LED4_COUNT, CRGB::Pink);
  fill_solid(leds5, LED5_COUNT, CRGB::Pink);
  FastLED.delay(588/4);
  off();
  fill_solid(leds1, LED1_COUNT, CRGB::Pink);
  fill_solid(leds2, LED2_COUNT, CRGB::Pink);
  fill_solid(leds3, LED3_COUNT, CRGB::Pink);
  fill_solid(leds4, LED4_COUNT, CRGB::Pink);
  fill_solid(leds5, LED5_COUNT, CRGB::Pink);
  FastLED.delay(588/4);
  off();
  fill_solid(leds1, LED1_COUNT, CRGB::Pink);
  fill_solid(leds2, LED2_COUNT, CRGB::Pink);
  fill_solid(leds3, LED3_COUNT, CRGB::Pink);
  fill_solid(leds4, LED4_COUNT, CRGB::Pink);
  fill_solid(leds5, LED5_COUNT, CRGB::Pink);
  FastLED.delay(588/4);
  off();

}

// Shakira (rotate above head) ------------------------------------------
void shakira() {
  fill_solid(leds2, LED2_COUNT, CRGB::Yellow);
  ballLeftUpYellow();
  fill_solid(leds1, LED1_COUNT, CRGB::Yellow);
  leds2.clear(); // Think this might work?
  clearLeftUp();
  fill_solid(leds4, LED4_COUNT, CRGB::Yellow);
  leds1.clear();
  clearRightUp();
  fill_solid(leds3, LED3_COUNT, CRGB::Yellow);
  leds4.clear();
  clearRightDown();
}

// Move to middle -------------------------------------------------------
void moveToMiddle(){
  fill_solid(leds1, LED1_COUNT, CRGB::AntiqueWhite);
  fill_solid(leds2, LED2_COUNT, CRGB::AntiqueWhite);
  fill_solid(leds3, LED3_COUNT, CRGB::AntiqueWhite);
  fill_solid(leds4, LED4_COUNT, CRGB::AntiqueWhite);
  ballAll();
}