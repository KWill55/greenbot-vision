#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//scree settings
const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

//Smiley Face 
const int SMILEY_RADIUS = 20;
const int LEFT_EYE_X = 56;
const int RIGHT_EYE_X = 72;
const int EYES_Y = 26;
const int EYE_RADIUS = 2;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();

   // Draw text at top
  display.setTextSize(1);              // Normal 1x scale
  display.setTextColor(WHITE); 
  display.setCursor(0, 0);             // Top-left corner
  display.println("Hi there!");
  display.display();                   // Show text before drawing the rest

  // Face outline
  display.drawCircle(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SMILEY_RADIUS, WHITE);

  // Eyes
  display.fillCircle(LEFT_EYE_X, EYES_Y, EYE_RADIUS, WHITE);  // left eye
  display.fillCircle(RIGHT_EYE_X, EYES_Y, EYE_RADIUS, WHITE);  // right eye

  // Smile (draw arc using segments)
  for (int x = -10; x <= 10; x++) {
    int y = (int)(0.05 * x * x); // parabola for curved smile
    display.drawPixel(64 + x, 40 - y, WHITE);
  }

  display.display();
}

void loop() {
  // Nothing here
}
