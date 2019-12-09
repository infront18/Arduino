void setup() {
 pinMode (A0, INPUT);
  Serial.begin (9600);
}

void loop() {
  Serial.print ("10진수값 : "); 
  Serial.println (analogRead(A0), DEC);
  Serial.print ("2진수값 : "); 
  Serial.println (analogRead(A0), BIN);
  Serial.print ("16진수값 : "); 
  Serial.println (analogRead(A0), HEX);
  Serial.print ("8진수값 : "); 
  Serial.println (analogRead(A0), OCT);
  Serial.println("   ");
  delay (2000);
}
