int arr[10]; //측정값 저장 배열변수
int index = 0; //reading[readIndex]로 측정된 값이 저장될 위치
int total = 0;  //측정한 값들의 전체합
int avg = 0; //측정한 값들의 평균값

void setup() {
  
  Serial.begin(9600);
  for (int i = 0; i < 10; i++) {
    arr[i] = analogRead(A0);  
        total = total + arr[i];
  }
}

void loop() {
  total = total - arr[index];  
  arr[index] = analogRead(A0);  
  total = total + arr[index];  
  index = index + 1;
  if(index >= 10)
  index = 0;
  
  avg = total / 10;
  
  Serial.print("total: ");
  Serial.println(total);
  delay(1000);
  Serial.print("average: ");
  Serial.println(avg);
  delay(1000);       
}
