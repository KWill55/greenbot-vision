#include <Servo.h>

Servo esc;

int escPin = 9;  // use pin 9 or 10 on Uno

// Pulse widths for your ESC (may need tweaking)
int neutralPulse = 1500;  // stop / brake
int forwardPulse = 1600;  // small forward
int reversePulse = 1400;  // small reverse (if ESC supports)

void setup() {
  esc.attach(escPin, 1000, 2000);  // typical ESC range
  esc.writeMicroseconds(neutralPulse);
  delay(3000);  // allow ESC to arm
}

void loop() {
  // forward
  esc.writeMicroseconds(forwardPulse);
  delay(1000);

  // brake (first neutral)
  esc.writeMicroseconds(neutralPulse);
  delay(1000);

  // reverse (after brake)
  esc.writeMicroseconds(reversePulse);
  delay(1000);

  // back to neutral (stop again)
  esc.writeMicroseconds(neutralPulse);
  delay(2000);
}
