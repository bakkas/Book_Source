int Pzo = 6;        // Pzo 변수에 피에조 부저를 6번 핀 설정
int dly = 1000;     // dly이라는 변수에 숫자 1000을 저장

void setup() {
  pinMode(Pzo, OUTPUT);
}

void loop() {
  analogWrite(Pzo, 64);   // PWM 25% 적용
  delay(dly);             // 1초 대기
  analogWrite(Pzo, 128);  // PWM 50% 적용
  delay(dly);             // 1초 대기
  analogWrite(Pzo, 256);  // PWM 100% 적용
  delay(dly);             // 1초 대기
}
