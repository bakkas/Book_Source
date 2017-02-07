#include <IRremote.h>
IRsend irsend;
int buttonPin = 4;

void setup() {
Serial.begin(9600); 
pinMode(buttonPin, INPUT); 
}

void loop() {
  Serial.println(digitalRead(buttonPin));
  if(!(digitalRead(buttonPin))) { 
    Serial.println("Data Sending ------------->>");
    irsend.sendNEC(0xFED02F, 32); 
    delay(200);
  }
}
