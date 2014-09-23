#include <Servo.h>

//Variables
float sensor;
int angle = 1;
Servo myservo;

// Csalibrating the sensor
int i;
int count;

void setup()  { 
  Serial.begin(9600);
//  myservo.attach(9);
//  myservo.write(angle);
  pinMode(A0, INPUT);
} 

void loop()  {
//  for (angle; angle <= 90; angle++) {
//    Serial.println(angle);
//    myservo.write(angle);
//    delay(500);
//  }
//  angle = 1;
  for (count = 0; count <=20; count++) {
    for (i = 0; i < 5; i++) {
      sensor += analogRead(A0);
      delay(200);    
    }
    Serial.println(sensor / 5.0);
    sensor = 0;
    delay(5000);
  }
}
  
  
