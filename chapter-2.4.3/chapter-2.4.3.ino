int LED =13;                   // 변수 LED에 11번 핀 번호 설정
int ReedSwitch = 7;            // 변수 ReedSwitch에 7번 핀 번호 설정
void setup() {
  Serial.begin(9600);         // 시리얼 모니터 Baudrate 설정
  pinMode(LED, OUTPUT);        // LED 핀 출력모드로 설정
}
void loop() {
  int readValue = digitalRead(ReedSwitch);  // D7에서 읽은 값을 readVal에 저장 
  Serial.println(readValue);
  if(readValue) {                           // readValue 값이 1이면 { } 내용 실행
    digitalWrite(LED, HIGH);                // LED를 켭니다.
  }
  else {                                    // readValue 값이 0이면 { } 내용 실행
    digitalWrite(LED, LOW);                 // LED를 끕니다.
  }
  delay(100);
}
