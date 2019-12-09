int LED = 8; 
int d = 1000;

void setup() {
 pinMode (A0, INPUT);
 pinMode (LED, OUTPUT);
 Serial.begin (9600);
}

void loop() {
  Serial.println (analogRead(A0));
  delay (200);
   digitalWrite (LED, 1);
  delay (d);
  digitalWrite (LED, 0);
  delay (d);

}
