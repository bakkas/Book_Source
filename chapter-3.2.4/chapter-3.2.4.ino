#include <Servo.h>
Servo myservo;
int pos = 0;

void setup() {
  myservo.attach(9);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1)   // 0부터 180까지 1씩 증가
    myservo.write(pos);     // 각도 조절(증가)
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // 180부터 0까지 1씩 감소
    myservo.write(pos);     // 각도 조절(감소)
    delay(15);
  }
}
