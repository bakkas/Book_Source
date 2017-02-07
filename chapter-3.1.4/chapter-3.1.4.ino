int pSensor = A0;                     // 조도센서 S핀 A0번에 연결
int relayPin = 7;                     // 릴레이 S(OUT)핀 7번에 연결 

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  int readVal = analogRead(pSensor);  // A0 조도센서 값 readVal에 저장
  Serial.print("Read Value =  ");    // 시리얼 모니터에
  Serial.println(readVal);           // 시리얼 모니터에 조도센서 값 프린트
  if(readVal <= 600) {                // 조도센서 값이 600 이하이면(어두워지면)
    digitalWrite(relayPin, LOW);      // 릴레이 켜기
  }
  else {                              // 조도센서 값이 600 이상이 아니면(밝으면)
    digitalWrite(relayPin, HIGH);     // 릴레이 끄기
  }
  delay(200);
}
