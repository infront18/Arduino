void setup() {
  pinMode(5, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin (9600);
}

void loop()
{
  if(digitalRead(5) > 0)
  {
    digitalWrite(8, HIGH);
    delay(1000);
    }
  else
  {
    digitalWrite(8, LOW);
    }
  Serial.println(digitalRead(5));
}
