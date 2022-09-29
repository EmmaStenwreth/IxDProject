#include <Adafruit_NeoPixel.h>
#include <Arduino_LSM6DSOX.h>

#define LED_PIN 3
#define LED_COUNT 39

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int motorPin = 2; // motor transistor connected to pin D2

int red, green, blue;

void setup() {
  // put your setup code here, to run once:

  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);

  strip.begin();
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<4; i++){
    red = random(255);
    green = random(255);
    blue = random(255);
    strip.setPixelColor(i, red, green, blue);
    delay(100);
    strip.clear();
    delay(100);    
  }
  
  //digitalWrite(motorPin, HIGH);
  //delay(1000);
  //digitalWrite(motorPin, LOW);
  //delay(1000);
}
