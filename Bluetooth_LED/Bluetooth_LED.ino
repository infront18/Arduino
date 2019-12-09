#include <SoftwareSerial.h>

SoftwareSerial myBlue(2, 3);

void setup() {
  Serial.begin(9600);
  myBlue.begin(9600);
  Serial.println("start");

}

void loop() {
  if(myBlue.available())
    Serial.write(myBlue.read());
  if(Serial.available())
    myBlue.write(Serial.read());
}
