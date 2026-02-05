#include <Servo.h>

Servo myServo;  

int servoPin = 9;   // attach servo signal wire here

void setup() {
  myServo.attach(servoPin);   // default pulse range 544–2400 µs
}

void loop() {
  // Turn left (0 degrees)
  myServo.write(0);      
  delay(1000);

  // Turn right (180 degrees)
  myServo.write(180);    
  delay(1000);

  // Back to center (90 degrees)
  myServo.write(90);     
  delay(1000);
}
