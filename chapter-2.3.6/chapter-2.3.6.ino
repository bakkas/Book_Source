void setup() {
  Serial.begin(9600);     // 시리얼 Baudrate 설정
  pinMode(13, OUTPUT);     // 13번 핀을 출력모드로 설정
}

void loop() {
  if (Serial.available()) {       // 시리얼 모니터의 입력이 있는지 체크
    char inChar = Serial.read();  // 시리얼 모니터 입력 값을 inChar 변수에 저장
    if(inChar == '1') {            // inChar과 ‘1’이 같은지 비교
      digitalWrite(13, HIGH);      // 같으면 13번 핀의 LED를 켬
    }
    else if(inChar == '0') {       // inChar과 ‘0’이 같은지 비교
      digitalWrite(13, LOW);       // 같으면 13번 핀의 LED를 끔
    }
  }
}
