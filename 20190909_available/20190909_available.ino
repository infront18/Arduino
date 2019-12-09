void setup() 
{
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available()) // >0 있어도 그만, 없어도 그만
  {
    char inchar = Serial.read();
    if (inchar == 'a')
    {
      digitalWrite(8, HIGH);
      Serial.println("불이 켜졌습니다.");
    }
    else if(inchar == 'b')
    {
      digitalWrite(8, LOW);
      Serial.println("불이 꺼졌습니다.");
    }
    else
    {
      Serial.println("a 또는 b를 입력하세요.");
    }
  }
}
