void setup() {
 pinMode(5, OUTPUT); //BUZZER
 pinMode(8, INPUT); //적외선 근접센서
 Serial.begin(9600); //시리얼 모니터 생성

}
int jumsu = 0;

void loop() {
  Serial.println(digitalRead(8));
    
  if(digitalRead(8) == 0)
  {
    digitalWrite(5, HIGH);
    jumsu+= 3;
    delay(2000);
    }
    
  else    //(digitalRead(8) == 1)
  {
    digitalWrite(5, LOW);
    }
  Serial.print("점수 : ");
  Serial.println(jumsu);
}
