const int VERT = A0;
const int HORIZ = A1;
const int SEL = 2;

void setup() {
  pinMode(SEL,INPUT);
  digitalWrite(SEL,HIGH);
  Serial.begin(9600);
}

void loop() {
  int vertical, horizontal, select;
  vertical = analogRead(VERT);
  horizontal = analogRead(HORIZ);
  select = digitalRead(SEL);

  Serial.print("vertical: ");
  Serial.print(vertical,DEC);
  Serial.print(" horizontal: ");
  Serial.print(horizontal,DEC);
  Serial.print(" select: ");
  if(select == HIGH) { Serial.println("not pressed"); }
  else { Serial.println("PRESSED!"); }
}
