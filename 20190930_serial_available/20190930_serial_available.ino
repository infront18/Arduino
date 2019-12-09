void setup() {
    pinMode(6, OUTPUT); //wheel left +
    pinMode(7, OUTPUT); //wheel left -
    pinMode(8, OUTPUT); //wheel right +
    pinMode(9, OUTPUT); //wheel right -
    Serial.begin(9600);
  }
  
void loop() {
  if(Serial.available())
  {
    char rccar = Serial.read();
    if(rccar == '1') //front
    {
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
    }
    
    else if(rccar == '2') //back
    {
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
    }
  
    else if(rccar == '5') //right
    {
      digitalWrite(6, HIGH);  
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    }
  
    else if(rccar == '4')  
    {
      digitalWrite(6, LOW); //left (4)
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
    }
  
    else if(rccar == '3')
    {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
    }
  }
} 
  
  
