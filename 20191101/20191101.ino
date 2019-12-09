int pump = 13;

void setup() {
  Serial.begin(9600);
  pinMode(pump, OUTPUT);

}

void loop() {
  digitalWrite(pump, HIGH);
  delay(5000);

}
