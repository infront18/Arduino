void setup() {
  pinMode (A0, INPUT); // X축
  pinMode (A1, INPUT); // Y축
  Serial.begin(9600); // 시리얼 통신을 시작하며, 통신속도는 9600  

}

void loop() {
  Serial.print("X : "); 
  Serial.print(analogRead(A0)); 
  Serial.print("    ");
  Serial.print("Y : "); 
  Serial.println(analogRead(A0)); 
  delay(500);
}
