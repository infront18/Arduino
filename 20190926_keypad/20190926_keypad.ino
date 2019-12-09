#include <Servo.h>
#include <Key.h>
#include <Keypad.h>

int tru=0;
int count=0;

const byte Rows = 4;
const byte Cols = 4;

char keymatrix[Rows][Cols] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

char pw[4] = {'1', '2', '3', '4'};


byte rowPins[Rows] = {9,8,7,6};
byte colPins[Cols] = {5,4,3,2};

Keypad mykeypad = Keypad(makeKeymap(keymatrix), rowPins, colPins, Rows, Cols);

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(10);
}

void loop() {
    
  char inputpw = mykeypad.getKey();
  
  if (inputpw)
  {
    Serial.println(inputpw);
    if(inputpw == pw[count])
    {
      count++;
      tru++;
    }
    else if(inputpw != pw[count])
    {
      count++;
    }
    if(inputpw == '#')
    {
      re();
    }

    if(count == 4)
    {
      if(tru==4)
        Su();
      else
        Fa();

     tru=0;
     count=0;
    }
  }

}

void Su()
{
  myservo.write(180);
  Serial.println("문이 열렸습니다.");
}

void Fa()
{
  Serial.println("비밀번호가 틀렸습니다.");
}

void re()
{
  tru=0;
  count=0;
  Serial.println("비밀번호 리셋");
}
