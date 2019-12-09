int LED = 8; 
int d = 1000;

void setup() {
 pinMode (A0, INPUT);
 pinMode (8, OUTPUT);
 Serial.begin (9600);
}

void loop() {
  Serial.println (analogRead(A0));
  if (analogRead(A0) >= 1000)
  {
    digitalWrite (8, HIGH);
  }
  else
  {
      digitalWrite (8, LOW);
  }
  
}
