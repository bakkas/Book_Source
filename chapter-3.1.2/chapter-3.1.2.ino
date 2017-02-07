#include <Adafruit_Sensor.h>            // Adafruit사의 센서 라이브러리 
#include <DHT.h>                       // DHT 센서 라이브러리 
#include <DHT_U.h>                      // DHT 통합 센서 라이브러리 
#include <Wire.h>                       // Wire.h 파일 가져오기
#include <LiquidCrystal_I2C.h>       // LiquidCrystal_I2C.h 파일 가져오기
#define DHTPIN            2             // DHT 센서 Signal D2번 핀에 연결
#define DHTTYPE           DHT11        // DHT 센서 종류(DHT11)

DHT_Unified dht(DHTPIN, DHTTYPE);       // dht 통합 객체 선언
uint32_t delayMS;                       // delay 시간 설정 객체
LiquidCrystal_I2C lcd(0x3F, 16, 2);  // 대부분 0x27 사용, 일부 0x3F 사용

void setup() {
  dht.begin();                          // dht 시작 함수 호출
  lcd.begin();                          // LCD 초기화
  sensor_t sensor;                      // 센서 객체 선언
  delayMS = sensor.min_delay / 1000;    // delay 시간 계산
}

void loop() {
  delay(delayMS);
  sensors_event_t event;                // envet 객체 선언
  lcd.backlight();                      // 백라이트 켜기
  dht.temperature().getEvent(&event);   // 온도 측정 함수 호출
  lcd.home();                           // lcd 커서를 0,0으로 이동
  lcd.print("temp : ");
  lcd.print(event.temperature);         // 온도 표시
  dht.humidity().getEvent(&event);      // 습도 측정 함수 호출
  lcd.setCursor(0,1);                   // lcd 커서를 두 번째 줄로 이동
  lcd.print("humi : ");
  lcd.print(event.relative_humidity);   // 습도 표시
}
