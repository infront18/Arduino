void setup() {
  pinMode(9, OUTPUT); //RED
}

void loop() {
  analogWrite(9, analogRead(A0));
}
