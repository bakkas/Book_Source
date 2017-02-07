void setup() {
  Serial.begin(9600);              // 시리얼모니터 Baudrate 설정
}

void loop() {
  for(int i=1;i<=10;i++) {          // 1부터 10 1씩 증가시키며 반복
    Serial.print("Pushup : ");     // 시리얼 모니터에 ’Pushup : ’ 프린트
    Serial.println(i);             // 시리얼 모니터에 변수 i 값 프린트
  }
  delay(1000);                      // 1초 지연
}
