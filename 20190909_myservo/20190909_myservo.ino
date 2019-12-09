#include <Servo.h>

Servo myservo; 

void setup() 
{
  myservo.attach(8);  
  myservo.write(90);
}

void loop() 
{
  int angle;

  for(angle = 0; angle < 180; angle++)
  {
    myservo.write(angle);
    delay(20);
  }
   for(angle = 180; angle > 0; angle--)
  {
    myservo.write(angle);
    delay(20);
  }
  
}
