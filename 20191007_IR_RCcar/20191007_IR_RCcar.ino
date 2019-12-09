#include <IRremote.h> //IRremote.h 라이브러리를 포함
int RECV_PIN = 3; //정수형 변수 RECV_PIN를 선언하고 3을 대입
IRrecv irrecv(RECV_PIN); //IR수신부를 RECV_PIN으로 설정
decode_results results;

void setup() {
  pinMode(6, OUTPUT); //wheel left +
  pinMode(7, OUTPUT); //wheel left -
  pinMode(8, OUTPUT); //wheel right +
  pinMode(9, OUTPUT); //wheel right -
  Serial.begin(9600);
  irrecv.enableIRIn(); //IR수신부 설정
}

void loop() {
    if(irrecv.decode(&results)){ //IR신호를 받으면
      switch(results.value)
      {
         case 0x511DBB : //2번 버튼
           digitalWrite(6, HIGH); //front
           digitalWrite(7, LOW);
           digitalWrite(8, HIGH);
           digitalWrite(9, LOW);
           break;

         case 0x52A3D41F : //4번 버튼
           digitalWrite(6, LOW); //left (4)
           digitalWrite(7, LOW);
           digitalWrite(8, HIGH);
           digitalWrite(9, LOW);
           break;

         case 0x20FE4DBB : //6번 버튼
          digitalWrite(6, HIGH); //right (4)
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          break;

         case 0xA3C8EDDB : //4번 버튼
          digitalWrite(6, LOW); //back (4)
          digitalWrite(7, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(9, HIGH);
          break;

         case 0xD7E84B1B : //5번 버튼
          digitalWrite(6, LOW); //stop (4)
          digitalWrite(7, LOW);
          digitalWrite(8, LOW);
          digitalWrite(9, LOW);
          break;

         default : 
           Serial.println(results.value, HEX); //시리얼 모니터에 받은 IR신호 출력
           break;
      }
    // 
    irrecv.resume(); //다음 신호를 받을 준비를 한다.
  }
  delay(200);
  

}
