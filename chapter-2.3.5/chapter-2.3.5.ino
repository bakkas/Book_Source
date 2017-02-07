void setup() {
  pinMode(7, INPUT);                  // 7번 핀을 입력 모드로 설정
  pinMode(13, OUTPUT);                // 13번 핀을 출력 모드로 설정
}

void loop() {
  if(digitalRead(7)){                 // 7번 핀 값이 1(버튼이 눌리면)이 되면
    digitalWrite(13, HIGH);           // 13번 핀 LED 켜기
  }
  else {                              // 7번 핀 값이 1이 아니면
    digitalWrite(13, LOW);            // 13번 핀 LED 끄기
  }
  delay(10);
} 
