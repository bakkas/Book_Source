int mLPin = 5;        // 모터가 정 방향으로 회전할 때 사용하는 핀
int mRPin = 6;        // 모터가 역 방향으로 회전할 때 사용하는 핀

void setup() {
  pinMode(mLPin, OUTPUT);
  pinMode(mRPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Input Motor Direction & Speed");
  Serial.println("ex, 1 100, 2 50, 3");
}

void loop() {
  if (Serial.available()) {
    long direction = Serial.parseInt(); // 모터의 회전방향 가져오기
    long speed = Serial.parseInt();     // 모터의 속도 값 가져오기
    Serial.println(direction);
    Serial.println(speed);
    if (direction == 1) {
      analogWrite(mLPin, speed);
    }
    else if (direction == 2) {
      analogWrite(mRPin, speed);
    }
    else if (direction == 3) {
      analogWrite(mLPin, 0);
      analogWrite(mRPin, 0);
    }
  }
}
