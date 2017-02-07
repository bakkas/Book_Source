#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3);

#define BLYNK_PRINT DebugSerial
#include <BlynkSimpleStream.h>

char auth[] = "529e41b7c7fe4aadb59650s5039eaxxx";

void setup() {
  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop() {
  Blynk.run();
}
