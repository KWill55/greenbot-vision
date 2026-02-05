#define ledOne 2
#define buzzer 7

// ========================
// Note frequency constants
// ========================
// Octave 3
#define C3  131
#define D3  147
#define E3  165
#define F3  175
#define G3  196
#define A3  220
#define B3  247

// Octave 4
#define C4  262
#define D4  294
#define E4  330
#define F4  349
#define G4  392
#define A4  440
#define B4  494

// Octave 5
#define C5  523
#define D5  587
#define E5  659
#define F5  698
#define G5  784
#define A5  880
#define B5  988

// Octave 6
#define C6  1047
#define D6  1175
#define E6  1319
#define F6  1397
#define G6  1568
#define A6  1760
#define B6  1976

// ========================
// Utility function
// ========================
void playNote(int pin, int frequency, int duration) {
  tone(pin, frequency, duration); 
  delay(duration);                
  noTone(pin);                    
  delay(50);                      
}

// ========================
// Scale functions
// ========================
void playAscending(int pin) {
  playNote(pin, C4, 400);
  playNote(pin, D4, 400);
  playNote(pin, E4, 400);
  playNote(pin, F4, 400);
  playNote(pin, G4, 400);
  playNote(pin, A4, 400);
  playNote(pin, B4, 400);
  playNote(pin, C5, 600);
}

void playDescending(int pin) {
  playNote(pin, C5, 400);
  playNote(pin, B4, 400);
  playNote(pin, A4, 400);
  playNote(pin, G4, 400);
  playNote(pin, F4, 400);
  playNote(pin, E4, 400);
  playNote(pin, D4, 400);
  playNote(pin, C4, 600);
}

// ========================
// Robot voice effect
// ========================
void playRobot(int pin) {
  // Do a few random chirps
  for (int i = 0; i < 10; i++) {
    int freq = random(400, 2000);       // random pitch
    int duration = random(80, 200);     // short beep
    tone(pin, freq, duration);
    delay(duration + random(20, 80));   // small random pause
  }

  // Do a quick upward sweep
  for (int freq = 600; freq < 1600; freq += 40) {
    tone(pin, freq, 20);
    delay(20);
  }

  // Do a quick downward sweep
  for (int freq = 1600; freq > 400; freq -= 35) {
    tone(pin, freq, 20);
    delay(20);
  }

  noTone(pin);
  delay(100);
}



// ========================
// Confirmation button 
// ========================
void playConfirm(int pin) {
  playNote(pin, E5, 100);  // E5
  playNote(pin, A5, 150);  // A5
}

// ========================
// Setup
// ========================
void setup() {
  pinMode(ledOne, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

// ========================
// Loop
// ========================
void loop() {
  digitalWrite(ledOne, HIGH);

  // Uncomment what you want to test:
  playAscending(buzzer);
  playDescending(buzzer);
  playRobot(buzzer);
  playConfirm(buzzer);

  digitalWrite(ledOne, LOW);
  delay(1000);
}
