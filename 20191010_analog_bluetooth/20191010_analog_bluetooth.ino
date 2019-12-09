#include <SoftwareSerial.h>

SoftwareSerial mybluetooth(2, 3);

void setup() {
  pinMode(A0, INPUT);
  mybluetooth.begin(9600);  
}

void loop() {
  mybluetooth.print("아날로그 값 : ");
  mybluetooth.println(analogRead(A0));
  delay(1000);
}
