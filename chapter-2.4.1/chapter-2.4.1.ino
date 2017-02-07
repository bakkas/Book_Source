int LED =11;      // 변수 LED에 11번 핀 번호 설정
void setup() {
  pinMode(LED, OUTPUT);
}
void loop() {
  int readVal = analogRead(A0);    // 아날로그 A0에서 읽은 값을 readVal 변수에 저장
  int brightVal = readVal / 4;     // readVal 값을 4로 나눈 결과를 brightVal에 저장
  analogWrite(LED, brightVal);     // LED를 PWM을 적용해 밝기 조절
  delay(10);
}
