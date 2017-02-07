#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>

char auth[] = "0e8204ef75aa41e98b6b35b1a7f38xxx";
char ssid[] = "youlnet";
char pass[] = "12345678";

SimpleTimer timer;
int pirPin = 0;               //D3(GPIO0)
int pirValue = 0;

void PirStateCheck() {
  pirValue= digitalRead(pirPin);
  Serial.println(pirValue);
  if (pirValue) {
    Serial.println("Motion Detect");
    Blynk.notify("Motion Detect");
    Blynk.email("papar@hanmail.net", "PIR Motion Detect!!", "Home PIR Motion Detect!!");
    Blynk.tweet("Home PIR Sensor Detect!!");
  }
  else { Serial.println("Motion NOT Detect"); }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, PirStateCheck);
}

void loop() {
  Blynk.run();
  timer.run();
} 
