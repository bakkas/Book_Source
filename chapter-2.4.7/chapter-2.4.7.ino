int tempPin = 0;                              // 온도센서 Output핀 A0번에 연결

void setup() {
  Serial.begin(9600);
}

void loop() {
  int readVal = analogRead(tempPin);          // A0 온도센서 값 readVal에 저장
  Serial.print((5.0*readVal*100.0)/1024.0);  // 시리얼 모니터에 계산 값 프린트
  Serial.println("℃");                
  delay(1000);
}
