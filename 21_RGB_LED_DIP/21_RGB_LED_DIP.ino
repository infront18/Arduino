void setup() {
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
}

void loop() {
  for(int i= 0; i < 255; i++) {
    digitalWrite(11, i);
    digitalWrite(10,255 - i);
    digitalWrite(9, i / 2);
    delay(1000);
  }
   for(int i= 0; i < 255; i++) {
    digitalWrite(11, 255 - i);
    digitalWrite(10, i / 2);
    digitalWrite(9, i);
    delay(1000);
  }
}
