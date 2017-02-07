void setup()  { 
  Serial.begin(9600);
} 

void loop()  { 
  int sensorValue = analogRead(A0);
  int percentValue = map(sensorValue, 0, 1023, 100, 0);
  Serial.print("Sensor Value : ");
  Serial.println(sensorValue);
  Serial.print("percentValue : ");
  Serial.println(percentValue);

  if(percentValue <=50) {
    Serial.println("Water Please~!!");
  }
  else if(percentValue <=40) {
    Serial.println("Emergency warning!! Water Please~!!");
  }
  delay(5000);
}
