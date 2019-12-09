void setup() {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(8));
  delay(1000);
}
