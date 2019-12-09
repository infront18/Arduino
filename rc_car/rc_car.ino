void setup() {
  pinMode(6, OUTPUT); //wheel left +
  pinMode(7, OUTPUT); //wheel left -
  pinMode(8, OUTPUT); //wheel right +
  pinMode(9, OUTPUT); //wheel right -
}

void loop() {
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(2000);

  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(2000);

  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(2000);

  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(2000);

  digitalWrite(6, LOW); //left (4)
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  delay(2000);

  digitalWrite(6, HIGH); //right (500000000000000000..........)
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(2000);
}
