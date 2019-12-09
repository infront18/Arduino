#include <SoftwareSerial.h>

SoftwareSerial mybluetooth(2, 3);

int Red = 10;
int Green = 9;
int Blue = 11;

void setup() {
  mybluetooth.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  if(mybluetooth.available())
  {
    char key = mybluetooth.read();
    mybluetooth.println(key);
    if(key == '1'){
      digitalWrite(Red, HIGH);
      digitalWrite(Green, LOW);
      digitalWrite(Blue, LOW);
    }
    if(key == '2'){
      digitalWrite(Red, LOW);
      digitalWrite(Green, HIGH);
      digitalWrite(Blue, LOW);
    }
    if(key == '3'){
      digitalWrite(Red, LOW);
      digitalWrite(Green, LOW);
      digitalWrite(Blue, HIGH);
      }
    if(key == '4'){
      digitalWrite(Red, LOW);
      digitalWrite(Green, LOW);
      digitalWrite(Blue, LOW);
    }
    if(key == '5'){
      digitalWrite(Red, HIGH);
      digitalWrite(Green, HIGH);
      digitalWrite(Blue, HIGH);
    }
    if(key == '6'){
      digitalWrite(Red, HIGH);
      digitalWrite(Green, LOW);
      digitalWrite(Blue, HIGH);
    }
    if(key == '7'){
      digitalWrite(Red, LOW);
      digitalWrite(Green, HIGH);
      digitalWrite(Blue, HIGH);
    }
    if(key == '8'){
      digitalWrite(Red, HIGH);
      digitalWrite(Green, HIGH);
      digitalWrite(Blue, LOW);
    }
   
   
      
  }
 

}
