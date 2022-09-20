
#include <Arduino_LSM6DSOX.h>

float Ax, Ay, Az;
float Gx, Gy, Gz;

int motorPin = 2; // motor transistor connected to pin D2

void setup() {
  // put your setup code here, to run once:

  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);

  while(!Serial);

  if(!IMU.begin()){
    Serial.println("Failed to initialize IMU!");
    while(1);
  }

  Serial.print("Acceleromeeter sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
  Serial.println();

  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println("Hz");
  Serial.println();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if(IMU.accelerationAvailable()) {
    IMU.readAcceleration(Ax, Ay, Az);

//    Serial.println("Accelerometer data: ");
//    Serial.print(Ax);
//    Serial.print('t');
//    Serial.println(Ay);
//    Serial.println('t');
//    Serial.println(Az);
//    Serial.println();

//    Serial.println("X: ");
//    Serial.println(Ax);
//    Serial.println("Y: ");
//    Serial.println(Ay);
//    Serial.println("Z: ");
//    Serial.println(Az); 

    Serial.println(String(Ax) + "." + String(Ay) + "." + String(Az));
  }

//  if(IMU.gyroscopeAvailable()) {
//    IMU.readGyroscope(Gx, Gy, Gz);
//
//    Serial.println("Gyroscope data: ");
//    Serial.print(Gx);
//    Serial.print('t');
//    Serial.print(Gy);
//    Serial.print('t');
//    Serial.print(Gz);
//    Serial.println();
//    //Serial.print();
//  }

  delay(500);

  //digitalWrite(motorPin, HIGH);
  //delay(1000);
  //digitalWrite(motorPin, LOW);
  //delay(1000);
}
