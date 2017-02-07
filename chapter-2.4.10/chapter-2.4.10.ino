#include <Adafruit_Sensor.h>          // Adafruit사의 센서 라이브러리 
#include <DHT.h>                     // DHT 센서 라이브러리 
#include <DHT_U.h>                    // DHT 통합 센서 라이브러리 
#define DHTPIN            2           // DHT 센서 Signal 2번 핀에 연결
#define DHTTYPE           DHT11      // DHT 센서 종류(DHT11)
DHT_Unified dht(DHTPIN, DHTTYPE);     // dht 통합 객체 선언
uint32_t delayMS;                     // delay 시간 설정 객체

void setup() {
  Serial.begin(9600); 
  dht.begin();                        // dht 시작 함수 호출
  sensor_t sensor;                    // 센서 객체 선언
  delayMS = sensor.min_delay / 1000;  // delay 시간 계산
}

void loop() {
  delay(delayMS);
  sensors_event_t event;               // envet 객체 선언
  dht.temperature().getEvent(&event);  // 온도 측정 함수 호출
    Serial.print("Temperature: ");
    Serial.print(event.temperature);  // 측정된 온도 시리얼 모니터에 프린트
    Serial.println(" *C");
  dht.humidity().getEvent(&event);     // 습도 측정 함수 호출
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);  // 측정된 습도 시리얼 모니터에 프린트
    Serial.println("%");
}
