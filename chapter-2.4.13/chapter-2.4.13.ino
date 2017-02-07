#include <Wire.h>                        // Wire.h 파일 가져오기
#include <LiquidCrystal_I2C.h>        // LiquidCrystal_I2C.h 파일 가져오기
LiquidCrystal_I2C lcd(0x27, 16, 2);   // 대부분 0x27 주소사용, 일부 0x3F 사용

void setup() {
  lcd.begin();                           // LCD 초기화
  lcd.backlight();                       // 백라이트 켜기
  lcd.print("Hello, world!");            // 메시지 띄우기
}

void loop() {
                                        // 이곳에 필요한 스케치 작성
}
