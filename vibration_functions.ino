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