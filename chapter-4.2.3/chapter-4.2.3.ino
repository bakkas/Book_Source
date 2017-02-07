#include <SoftwareSerial.h>
#include <SPI.h>
#include <DHT.h>
#include <SimpleTimer.h>

SoftwareSerial DebugSerial(2, 3);
#define DHTPIN            4
#define DHTTYPE           DHT11
#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleStream.h>

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

char auth[] = "529e41b7c7fe4aadb59650s5039eaxxx";

void sendSensor() {
  float t = dht.readTemperature(); 
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V4, t);
  Blynk.virtualWrite(V5, h);
}

void setup() {
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  Blynk.run();
  timer.run();
}
