#include <IRremote.h> //IRremote.h 라이브러리를 포함
int RECV_PIN = 3; //정수형 변수 RECV_PIN를 선언하고 3을 대입
IRrecv irrecv(RECV_PIN); //IR수신부를 RECV_PIN으로 설정
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); //IR수신부 설정
}

void loop() {
  if(irrecv.decode(&results)){ //IR신호를 받으면
    Serial.println(results.value, HEX); //시리얼 모니터에 받은 IR신호 출력
    irrecv.resume(); //다음 신호를 받을 준비를 한다.
  }
  delay(200);
}
