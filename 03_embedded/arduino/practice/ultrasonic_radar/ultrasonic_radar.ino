#define TRIG_PIN 9   // Ultrasonic sensor TRIG
#define ECHO_PIN 10  // Ultrasonic sensor ECHO
#define LED_PIN 7    // LED pin

//make sure power is at 5v because 3.3v does not work

// Speed of sound constant
#define SOUND_SPEED 0.0343 // cm per microsecond

// Threshold distance (2 feet ≈ 61 cm)
#define THRESHOLD_CM 61

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Send a 10us HIGH pulse to trigger the ultrasonic burst
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the time for echo to return
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to distance (cm)
  float distanceCm = duration * SOUND_SPEED / 2.0;

  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // If object is within 2 feet, flash LED
  if (distanceCm > 0 && distanceCm <= THRESHOLD_CM) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  } else {
    digitalWrite(LED_PIN, LOW); // LED stays off otherwise
  }

  delay(100); // short delay before next reading
}
