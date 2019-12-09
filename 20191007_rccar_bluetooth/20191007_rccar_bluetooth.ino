#include <SoftwareSerial.h>

SoftwareSerial mybluetooth (2,3);// {블루투스}tx쪽이 2번,{}rx->3)  

void setup() 
{
 pinMode (6, OUTPUT); //왼쪽 +
 pinMode (7, OUTPUT); //왼쪽 -
 pinMode (8, OUTPUT); //오른쪽 +
 pinMode (9, OUTPUT); //오른쪽 -
 mybluetooth.begin (9600);
}

void loop() //모니터에서 숫자를 누르면 실행이되는 소스
{
    char rccar = mybluetooth.read();
      if(rccar == '1')
      {
      digitalWrite (6, HIGH); // 전진 '1'
      digitalWrite (7, LOW);
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      }
      
      else if(rccar == '2')
      {
      digitalWrite (6, LOW); //  후진 '2'
      digitalWrite (7, HIGH);
      digitalWrite (8, LOW);
      digitalWrite (9, HIGH);
      }
      
      else if(rccar == '4')
      {
      digitalWrite (6, LOW);//   오른쪽
      digitalWrite (7, LOW);
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      }
        
      
      else if(rccar == '5')
      {
      digitalWrite (6, HIGH);// 왼쪽
      digitalWrite (7, LOW);
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      }
      
      else if (rccar == '3')
      {
      digitalWrite (6, LOW);//   정지
      digitalWrite (7, LOW);
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      }

      else if(rccar == '6')
      {
      digitalWrite (6, HIGH);// left turn
      digitalWrite (7, LOW);
      digitalWrite (8, LOW);
      digitalWrite (9, HIGH);
      }

       else if(rccar == '7')
      {
      digitalWrite (6, LOW); // right turn
      digitalWrite (7, HIGH);
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      }
  
  
} 
