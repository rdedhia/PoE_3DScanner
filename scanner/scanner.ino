#include <Servo.h>

//Variables
int count = 0;
int sensor;
float sensor_avg;
byte angle = 20;
byte angle2 = 20;
Servo myservo;
Servo myservo2;
const byte servos[] = {9,10};
byte interval = 80;
long previousMillis = 0;
long currentMillis;

void setup()  { 
  Serial.begin(9600);
  myservo.attach(servos[0]);
  myservo2.attach(servos[1]);
  pinMode(A0, INPUT);
} 

void loop()  {  
  for (angle; angle < 60; angle++) {
    myservo.write(angle);
    for (angle2; angle2 < 60; angle2++) {
      print_angles();
      sensor_avg = measure();
    }
    angle++;
    myservo.write(angle);
    for (angle2; angle2 > 20; angle2--) {
      print_angles();
      sensor_avg = measure();
    }
  }
}

void print_angles() {
  Serial.print("Angle 1: ");
  Serial.print(angle);
  Serial.print(" Angle 2: ");
  Serial.println(angle2);
  myservo2.write(angle2);
}
  
float measure() {
  count = 0;
  sensor = 0;
  
  while (count < 5) {
    currentMillis = millis();
    if (currentMillis - previousMillis > interval) {
      sensor += analogRead(A0);
      previousMillis = currentMillis;
      count += 1;
    }    
  }
  float sensor_avg = sensor / 5.0;
  Serial.print("Sensor average: ");
  Serial.println(sensor_avg);
  return sensor_avg;
}
