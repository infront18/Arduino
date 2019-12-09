int val = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  if(analogRead(A0) < 30)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);  
  }
  val = analogRead(A0);
  Serial.println(val);
  delay(1000);
}
