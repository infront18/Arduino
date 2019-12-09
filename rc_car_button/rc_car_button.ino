void setup() {
  pinMode(6, OUTPUT); //wheel left +
  pinMode(7, OUTPUT); //wheel left -
  pinMode(8, OUTPUT); //wheel right +
  pinMode(9, OUTPUT); //wheel right -
  pinMode(10, INPUT_PULLUP); //front
  pinMode(11, INPUT_PULLUP); //back
  pinMode(12, INPUT_PULLUP); //left
  pinMode(13, INPUT_PULLUP); //right
}

void loop() {
  if(digitalRead(10) == LOW) //front
  {
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else if(digitalRead(11) == LOW) //back
  {
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }
  else if(digitalRead(12) == LOW) //right
  {
    digitalWrite(6, HIGH); //right 
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  else if(digitalRead(13) == LOW) //left
  {
    digitalWrite(6, LOW); //left (4)
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  else
  {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
 
}
