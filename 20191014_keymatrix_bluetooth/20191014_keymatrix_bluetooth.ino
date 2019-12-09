#include <SoftwareSerial.h>

SoftwareSerial mybluetooth(2, 3);

void setup() {
  Serial.begin(9600);
  mybluetooth.begin(9600);
}

void loop() {
  if(mybluetooth.available())
  {
    char keymatrix = mybluetooth.read();
    Serial.println(keymatrix);
  }
}
