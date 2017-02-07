#include <SoftwareSerial.h>
#define LED 13
SoftwareSerial btSerial(2,3);

void setup() {
  pinMode(LED, OUTPUT);
  btSerial.begin(9600);
}

void loop() {
   if(btSerial.available()) {
      char c = btSerial.read();

      switch(c) {
        case 'a':
          digitalWrite(LED, HIGH);
          break;
        case 'b':
          digitalWrite(LED, LOW);
          break;
      }
   }
  delay(10);
} 
