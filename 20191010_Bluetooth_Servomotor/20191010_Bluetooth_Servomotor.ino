#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mybluetooth(2, 3); //tx 2, rx 3
Servo myservo;

void setup() {
  myservo.attach(7);
  mybluetooth.begin(9600);
  myservo.write(0);
}

int angle = 0;

void loop() {
  if(mybluetooth.available());
  {
    angle = mybluetooth.read();
    myservo.write(angle);
  }

}
