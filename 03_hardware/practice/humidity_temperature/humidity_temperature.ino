#include "DHT.h"

#define DHTPIN 2       // Pin connected to the DHT sensor data pin
#define DHTTYPE DHT11  

//left pin is signal, middle is Vcc, right is GND

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT Sensor Reading Practice");
  dht.begin();
}

void loop() {
  // Wait a bit between readings (DHT11 needs ~2s)
  delay(2000);

  // Read humidity and temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();      // Celsius
  float f = dht.readTemperature(true);  // Fahrenheit

  // Check if any reading failed
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C  /  ");
  Serial.print(f);
  Serial.println(" °F");
}
