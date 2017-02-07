int piezoPin = 5;
int echoPin = 6;
int trigPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(piezoPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() { 
  float duration, cm;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);           // 초음파 센서 응답 시간 체크
  cm = ((float)(340 * duration) / 10000) / 2; // 응답시간을 거리(cm)로 계산
  noTone(piezoPin);
  Serial.println(cm);

  if(cm<100 && cm>=70)     { tone(piezoPin, 2000, 300); delay(1000); }
  else if(cm<70 && cm>=50) { tone(piezoPin, 2000, 200); delay(500);  }
  else if(cm<50 && cm>=30) { tone(piezoPin, 2000, 100); delay(200);  }
  else if(cm<30)           { tone(piezoPin, 2000, 50); delay(20);    }
}
