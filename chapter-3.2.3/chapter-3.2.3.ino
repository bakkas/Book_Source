int buttonPin = 5;
int motorPin = 6; 
int level = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  if (!digitalRead(buttonPin)) {    // 버튼이 눌렸을 경우에만 { } 실행
    if (level == 0) {
      analogWrite(motorPin, 70);
      level++;
    }
    else if (level == 1) {
      analogWrite(motorPin, 150);
      level++;
    }
    else if (level == 2) {
      analogWrite(motorPin, 255);
      level++;
    }
    else if (level == 3) {
      analogWrite(motorPin, 0);
      level=0;
    }
  }
  delay(200);
}
