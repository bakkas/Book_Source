int ledPin = 13;                // LED 연결핀
int inputPin = 7;               // 센서 시그널 핀
int pirState = LOW;             // PIR 초기상태
int val = 0;                    // Signal 입력 값
 
void setup() {
    pinMode(ledPin, OUTPUT);    // LED Output 설정
    pinMode(inputPin, INPUT);   // 센서 Input 설정
    Serial.begin(9600);
}

void loop(){
    val = digitalRead(inputPin);                // PIR 센서 값 읽어 val에 넣기
    if (val == HIGH) {                          // 인체감지 상태이면
        digitalWrite(ledPin, HIGH);             // LED 켜기
        if (pirState == LOW) {
          Serial.println("Motion detected!");  // 시리얼모니터에 메시지 프린트
          pirState = HIGH;
        }
    } else {
        digitalWrite(ledPin, LOW);              // LED 끄기
        if (pirState == HIGH){        
            Serial.println("Motion ended!");   // 시리얼모니터에 메시지 프린트
            pirState = LOW;
        }
    } 
}


