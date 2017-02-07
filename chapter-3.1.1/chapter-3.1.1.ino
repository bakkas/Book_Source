int redPin = 9;                     //RGB red
int greenPin = 10;                  //RGB green
int bluePin = 11;                   //RGB blue

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int redRate;                      //RED_PIN에 출력시킬 값 저장하기 위한 변수
  int greenRate;                    //GREEN_PIN에 출력시킬 값 저장하기 위한 변수
  int blueRate;                     //BLUE_PIN에 출력시킬 값 저장하기 위한 변수
  for (int i = 0; i < 768; i++) {   //i가 0~767이 될 때 까지 { }안의 내용을 반복 
    if (i <= 255) {                 //빨강 -> 초록
      redRate = 255 – i;            //빨강을 점점 줄임
      greenRate = i;                //초록을 점점 높임
      blueRate = 0;                 //파랑은 없음
    }
    else if (i <= 511) {            //초록 -> 파랑
      redRate = 0;                  //빨강은 없음                   
      greenRate = 255 - (i – 256);  // 초록을 점점 줄임
      blueRate = (i – 256);          //파랑을 점점 높임
    }
    else {                           //파랑 ->  빨강
      redRate = (i – 512);           //빨강을 점점 높임
      greenRate = 0;                 //초록은 없음                
      blueRate = 255 - (i – 512);    //파랑을 점점 줄임
    }
    analogWrite(redPin, redRate);    //RED_PIN으로 redRate만큼 아날로그 값 출력
    analogWrite(greenPin, greenRate);//GREEN_PIN으로 greenRate만큼 아날로그 값 출력
    analogWrite(bluePin, blueRate);  //BLUE_PIN으로 blueRate만큼 아날로그 값 출력
    delay(30); 
  }
}
