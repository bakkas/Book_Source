void setup() {
  pinMode(11, OUTPUT);    // 11번 핀을 출력모드로 설정
  pinMode(12, OUTPUT);    // 12번 핀을 출력모드로 설정
  pinMode(13, OUTPUT);    // 13번 핀을 출력모드로 설정
}

void loop() {
  digitalWrite(11, HIGH);   // 11번 핀에 전압 공급
  delay(2000);              // 2초 동안 유지
  digitalWrite(11, LOW);    // 11번 핀에 전압 차단
  digitalWrite(12, HIGH);   // 12번 핀에 전압 공급
  delay(1000);              // 1초 동안 유지
  digitalWrite(12, LOW);    // 12번 핀에 전압 차단
  digitalWrite(13, HIGH);   // 13번 핀에 전압 공급
  delay(2000);              // 2초 동안 유지
  digitalWrite(13, LOW);    // 13번 핀에 전압 차단
}
