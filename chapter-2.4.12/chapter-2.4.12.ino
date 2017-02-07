int relayPin = 7;
void setup() {
  pinMode(relayPin, OUTPUT);
}

void loop() {
  digitalWrite(relayPin, HIGH);   // 릴레이 끄기
  delay(3000);
  digitalWrite(relayPin, LOW);    // 릴레이 켜기
  delay(2000);
}
