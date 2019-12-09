void setup() {
  pinMode(6, OUTPUT); //wheel left +
  pinMode(7, OUTPUT); //wheel left -
  pinMode(8, OUTPUT); //wheel right +
  pinMode(9, OUTPUT); //wheel right -
  pinMode(10, INPUT_PULLUP); //front
  pinMode(11, INPUT_PULLUP); //back
  pinMode(12, INPUT_PULLUP); //left
  pinMode(13, INPUT_PULLUP); //right
  pinMode(A0, INPUT); //y축
  pinMode(A1, INPUT); //x축
}

void loop() {
  if(analogRead(A0) < 10) //front
  {
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
  }
  
  else if(analogRead(A0) > 1010) //back
  {
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
  }

  else if(analogRead(A1) < 10) //right
  {
    digitalWrite(6, HIGH);  
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }

  else if(analogRead(A1) > 1010)
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
  
  
