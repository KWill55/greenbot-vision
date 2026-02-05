#include <Servo.h>

Servo myServo;  // create servo object
int servoPin = 9;  

void setup() {
  myServo.attach(servoPin);  // attach servo to pin
  Serial.begin(9600);        
  Serial.println("Servo ready. Type an angle (0-180).");
}

void loop() {
  // Example: cycle through angles automatically
  myServo.write(0);
  delay(1000); // wait 1 second
  myServo.write(90);
  delay(1000);
  myServo.write(180);
  delay(1000);

}
