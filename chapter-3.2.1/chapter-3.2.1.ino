int mortorPin = 9;

void setup() {
  pinMode(mortorPin, OUTPUT);
}

void loop() {
  analogWrite(mortorPin, 150);    //모터 구동(중간 속도)
  delay(3000);
  analogWrite(mortorPin, 255);    //모터 구동(최대 속도)
  delay(3000);  
  analogWrite(mortorPin, 0);    //모터 구동 중지
  delay(3000);
}
