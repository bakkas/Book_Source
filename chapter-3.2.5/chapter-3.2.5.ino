#include <Servo.h>
Servo myservo;
int pos = 0;
int echoPin = 6;
int trigPin = 7;
int servoPin = 9;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);    // 서버 모터 연결 핀 번호 정의
  myservo.write(0);            // 초기 서보모터 각도 0도로 초기화
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
}

void loop() { 
  float duration, cm;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin,HIGH);           // 초음파 센서 응답 시간 체크
  cm = ((float)(340 * duration) / 10000) / 2; // 응답시간을 거리(cm)로 계산
  Serial.println(cm);
  if(cm <= 40) {
    myservo.write(60);                        // 휴지통 열 수 있는 각도
    delay(500);
  }
  else{
    myservo.write(0);                         // 휴지통 닫는 각도
    delay(500);
  }
}
