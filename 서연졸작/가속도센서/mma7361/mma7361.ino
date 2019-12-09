#include <AcceleroMMA7361.h>

int x; 
int y; 
int z; 
void setup()
{ 
   pinMode(7, OUTPUT);
   Serial.begin(9600); 
}
void loop()
{
  x = analogRead(0); 
  y = analogRead(1); 
  z = analogRead(2); 

  if(y<100 && z<100)
    digitalWrite(7, HIGH);
  else
    digitalWrite(7, LOW);
  
  Serial.print("  X = "); 
  Serial.print(x);
  Serial.print("  Y = "); 
  Serial.print(y);
  Serial.print("  Z = "); 
  Serial.println(z);
  
  delay(1000);
}
