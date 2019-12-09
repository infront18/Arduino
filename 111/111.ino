int pb = 5;
int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  pinMode(pb, OUTPUT);

}

void loop() 
  
  if (digitalWrite(8) == 0)
  {
    digitalWrite(5, HIGH);
    }
  else    //(digitalRead(8) == 1)
  {
    digitalWrite(5, LOW);
    }
  
  int a = map(light, 0, 1023, melody[0], melody[7]);
  tone(pb, a, 1000);

}
