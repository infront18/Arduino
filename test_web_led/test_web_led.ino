void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char ch;
  if(Serial.available())
  {
    ch=Serial.read();
    if( ch == '0' )       
      digitalWrite(13,  LOW);
    else if( ch == '1' )  
      digitalWrite(13, HIGH);
    else;
  }

}
