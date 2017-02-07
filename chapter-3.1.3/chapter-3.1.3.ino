int measurePin = 0; 
int ledPower = 2;       
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPower,OUTPUT);
}

void loop(){
  digitalWrite(ledPower,LOW);           // power off the LED
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measurePin);  // read the dust value
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);          // power on the LED
  delayMicroseconds(sleepTime);

  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = 0.17 * calcVoltage - 0.1;

  Serial.print("Raw Signal Value (0-1023): ");
  Serial.print(voMeasured);
  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);
  Serial.print(" - Dust Density: ");
  Serial.println(dustDensity);          // unit: mg/m3
  delay(1000);
}
