#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int data = 3;
IRrecv irrecv(data); //적외선 수신기 초기화
decode_results results; //수신 데이터 = result

void setup() {
   pinMode (6, OUTPUT); //왼쪽 +
   pinMode (7, OUTPUT); //왼쪽 -
   pinMode (8, OUTPUT); //오른쪽 +
   pinMode (9, OUTPUT); //오른쪽 -
   Serial.begin(9600); // 시리얼 통신 속도 115200로 설정
   irrecv.enableIRIn(); // 적외선 수신기 시작하기
}

void loop() 
{
  if(irrecv.decode(&results) == 0x511DBB)
  {
    digitalWrite (6, HIGH); // 전진
    digitalWrite (7, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (9, LOW);
    Serial.println(results.value, HEX);
  }
  
  else if(irrecv.decode(&results) == 0xA3C8EDDB)
  {
    digitalWrite (6, LOW); //  후진
    digitalWrite (7, HIGH);
    digitalWrite (8, LOW);
    digitalWrite (9, HIGH);
    Serial.println(results.value, HEX);
  }
  
  else if(irrecv.decode(&results) == 0x20FE4DBB)
  {
    digitalWrite (6, LOW);//   오른쪽
    digitalWrite (7, LOW);
    digitalWrite (8, HIGH);
    digitalWrite (9, LOW);
    Serial.println(results.value, HEX);
  }
    
  
  else if(irrecv.decode(&results) == 0x52A3D41F)
  {
    digitalWrite (6, HIGH);// 왼쪽
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    digitalWrite (9, LOW);
    Serial.println(results.value, HEX);
  }
  
  else if(irrecv.decode(&results) == 0xD7E84B1B)
  {
    digitalWrite (6, LOW);//   정지
    digitalWrite (7, LOW);
    digitalWrite (8, LOW);
    digitalWrite (9, LOW);
    Serial.println(results.value, HEX);
  }
  
  else
  {
    Serial.println (results.value, HEX);
  }
  irrecv.resume(); //다음 신호를 받을 준비를 한다.
  delay(300);
  
} 
