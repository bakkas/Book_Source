int pSensor = A0;      // 조도센서 S핀 A0번에 연결
int ledPin = 11;       // LED 핀 11번에 연결 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int readVal = analogRead(pSensor);   // A0 조도센서 값 readVal 변수에 저장
  Serial.print("Read Value =  ");     // 시리얼 모니터에 " " 내용 프린트
  Serial.println(readVal);            // 시리얼 모니터에 조도센서 값 프린트
  if(readVal <= 600) {                 // 조도센서 값이 600 이하이면 
    digitalWrite(ledPin, HIGH);        // LED 켜기
  }
  else {                               // 조도센서 값이 600 미만이면
    digitalWrite(ledPin, LOW);         // LED 끄기
  }
  delay(200);
}
