int dCheck = 7;
int aCheck = A0;
int bluePin = 9;
int redPin = 11; 

void setup() {
  pinMode(dCheck, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int analogValue = analogRead(aCheck);
  int digitalValue = digitalRead(dCheck);
  int Result = map(analogValue, 0, 1023, 0, 255);

  if(analogValue <= 100) {
    analogWrite(redPin, 0);
    analogWrite(bluePin, 255);
  }
 else{
    analogWrite(redPin, Result);
    analogWrite(bluePin,255-Result);
  }
  Serial.println("-------------");
  Serial.println(analogValue);
  Serial.println(digitalValue);
  Serial.println(Result);
  delay(500);
}
