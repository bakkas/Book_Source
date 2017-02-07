#define C 262                   // 도 
#define D 294                   // 레 
#define E 330                   // 미 
#define F 349                   // 파 
#define G 392                   // 솔 
#define A 440                   // 라 
#define B 494                   // 시 
#define H 523                   // 도(높은)

int pzoPin = 6;                 // 피에조 S(+)를 6번에 연결 
int tempo = 200;                // 음 재생 시간 설정 
int notes[25] = { G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C }; 

void setup() { 
  pinMode (pzoPin, OUTPUT); 
} 

void loop() { 
  for (int i = 0; i < 12; i++) { 
    tone (pzoPin, notes[ i ], tempo); 
    delay (300); 
  } 
  delay(100);                   // 연주 중간에 잠시 지연시키는 용도 

  for (int i = 12; i < 25; i++) { 
    tone (pzoPin, notes[ i ], tempo); 
    delay(300); 
  } 
}
