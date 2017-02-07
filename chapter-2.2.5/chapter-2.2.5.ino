void setup() {
  pinMode(7, INPUT);                // 7번 핀을 입력 모드로 설정
  Serial.begin(9600);              // 시리얼 Baudrate 9600으로 설정
}
void loop() {
  Serial.println(digitalRead(7));  // 시리얼 모니터에 버튼 값 프린트
  delay(10);                        // 0.01초 지연
} 
