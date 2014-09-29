#include <Servo.h>

// Creating Servo objects to easily write angles to the servos
Servo myservo;
Servo myservo2;
const byte servos[] = {9,10}; // Pin numbers for servos

int count = 0; // Counter for number of measurements at each pan/tilt angle permutation
int sensor; // Value for each sensor measurement taken using AnalogRead (on 0-1023 range)
float sensor_avg; // Average of five sensor measurements at each pan/tilt angle permutation

// Starting pan and tilt angle measurements
byte angle = 50;
byte angle2 = 30;

byte interval = 50; // 50ms interval between measurements
long previousMillis = 0; // Time of last measurement
long currentMillis; // Current time, taken using millis()

void setup()  { 
  Serial.begin(9600);
  // Attaching Servo objects to pins defined in servos[]
  myservo.attach(servos[0]);
  myservo2.attach(servos[1]);
  // Reading sensor values from A0
  pinMode(A0, INPUT);
} 

void loop()  {
  // Iterating over panning angle
  for (angle; angle < 140; angle++) {
    myservo.write(angle);
    // Iterating over tilting angle
    for (angle2; angle2 < 130; angle2++) {
      myservo2.write(angle2);
      // Calling measure function to take, average, and print sensor measurements
      measure();
    }
    angle++;
    myservo.write(angle);
    // Iterating backwards to sweep tilting angle, because it requires the servo to move
    // significantly less
    for (angle2; angle2 > 30; angle2--) {
      myservo2.write(angle2);
      measure();
    }
  }
}
  
void measure() {
  // Reset values of count and sensor on each function call
  count = 0;
  sensor = 0;
  
  while (count < 5) {
    currentMillis = millis();
    if (currentMillis - previousMillis > interval) {
      // Take measurement if it has been 'interval' time since the last measurement
      sensor += analogRead(A0);
      previousMillis = currentMillis;
      count += 1;
    }    
  }
  float sensor_avg = sensor / 5.0;
  Serial.println(sensor_avg);
}
  
