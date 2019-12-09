#include <IRremote.h> //IRremote.h 라이브러리를 포함

int RECV_PIN = 3; //정수형 변수 RECV_PIN를 선언하고 3을 대입
IRrecv irrecv(RECV_PIN); //IR수신부를 RECV_PIN으로 설정
decode_results results;

int front=0x511DBB;
int left=0x52A3D41F;
int right=0x20FE4DBB;
int back=0xA3C8EDDB;
int halt=0xD7E84B1B;

void setup() {
	pinMode(6, OUTPUT); //wheel left +
	pinMode(7, OUTPUT); //wheel left -
	pinMode(8, OUTPUT); //wheel right +
	pinMode(9, OUTPUT); //wheel right -
	Serial.begin(9600);
	irrecv.enableIRIn(); //IR수신부 설정
}

void loop() {
	if(irrecv.decode(&results) == front){ //IR신호를 받으면
	digitalWrite(6, HIGH); //front
	digitalWrite(7, LOW);
	digitalWrite(8, HIGH);
	digitalWrite(9, LOW);
	}
	if else(irrecv.decode(&results) == left){
	digitalWrite(6, LOW); //left (4)
	digitalWrite(7, LOW);
	digitalWrite(8, HIGH);
	digitalWrite(9, LOW);
	}
	if else(irrecv.decode(&results) == right){
	digitalWrite(6, HIGH); //right (4)
	digitalWrite(7, LOW);
	digitalWrite(8, LOW);
	digitalWrite(9, LOW);
	}
	if else(irrecv.decode(&results) == back){
	digitalWrite(6, LOW); //back (4)
	digitalWrite(7, HIGH);
	digitalWrite(8, LOW);
	digitalWrite(9, HIGH);
	}
	if else(irrecv.decode(&results) == halt){
	digitalWrite(6, LOW); //stop (4)
	digitalWrite(7, LOW);
	digitalWrite(8, LOW);
	digitalWrite(9, LOW);
	}
	else{
	Serial.println(results.value, HEX); //시리얼 모니터에 받은 IR신호 출력
	}

	irrecv.resume(); //다음 신호를 받을 준비를 한다.

	delay(200);


}