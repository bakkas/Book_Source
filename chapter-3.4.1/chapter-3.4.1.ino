#include <IRremote.h>
int RECV_PIN = 2; 
IRrecv irrecv(RECV_PIN);
decode_results results;

const int AIA = 5;  
const int AIB = 6;  
const int BIA = 9; 
const int BIB = 10;  
byte speed = 100; 

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void forward() {
  analogWrite(AIA, speed);  analogWrite(AIB, 0);
  analogWrite(BIA, speed);  analogWrite(BIB, 0);
}
void backward() {
  analogWrite(AIA, 0);  analogWrite(AIB, speed);
  analogWrite(BIA, 0);  analogWrite(BIB, speed);
}

void left() {
  analogWrite(AIA, speed);  analogWrite(AIB, 0);
  analogWrite(BIA, 0);       analogWrite(BIB, speed);
}

void right() {
  analogWrite(AIA, 0);      analogWrite(AIB, speed);
  analogWrite(BIA, speed);  analogWrite(BIB, 0);
}

void stop() {
  analogWrite(AIA, 0);  analogWrite(AIB, 0);
  analogWrite(BIA, 0);  analogWrite(BIB, 0);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if(results.value == 16736925) {
      Serial.println("Motor Forward");
      forward();
    }
    if(results.value == 16754775) {
      Serial.println("Motor Backward");
      backward();
    }
    if(results.value == 16720605) {
      Serial.println("Motor Left");
      left();
    }
    if(results.value == 16761405) {
      Serial.println("Motor Right");
      right();
    }
    if(results.value == 16712445) {
      Serial.println("Motor Stop");
      stop();
    }
    irrecv.resume();
  }
}
