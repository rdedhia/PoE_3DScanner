#include <Servo.h>

//Variables
int sensor;
int angle = 1;
Servo myservo;

void setup()  { 
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(angle);
  pinMode(A0, INPUT);
} 

void loop()  {
  for (angle; angle <= 90; angle++) {
    Serial.println(angle);
    myservo.write(angle);
    delay(500);
  }
  angle = 1;
  
  sensor = analogRead(A0);
  //Serial.println(sensor);
  delay(1000); 
}
  
  
