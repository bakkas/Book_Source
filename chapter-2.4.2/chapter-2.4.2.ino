int mSensor = A0;         // 사운드센서 A0핀 A0에 연결
int ledPin = 11;          // LED 핀 11번에 연결 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int readValue = analogRead(mSensor);    // A0 사운드센서 값 readVal 변수에 저장
  int lightValue = readValue / 4;         // LED 값으로 사용하기 위해 4로 나눔 
  Serial.print("Read Value =  ");         
  Serial.println(readValue);             // 시리얼 모니터에 사운드센서 값 프린트
  Serial.print("Light Value =  ");         
  Serial.println(lightValue);            // 시리얼 모니터에 LED 밝기 값 프린트
  analogWrite(ledPin, lightValue);        // LED 켜기
  delay(200);
}
