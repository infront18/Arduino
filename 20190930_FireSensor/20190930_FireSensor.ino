void setup() {
    pinMode(A0, INPUT);
    Serial.begin(9600);
     
}
  
void loop() {
    int val=0;
    int arr[10];
    int total=0;
    int avg=0;
    
    for(int i=0; i<10; i++) {
    arr[i] = analogRead(A0);
    total+=arr[i];

    Serial.println(arr[i]);
    }
    
    avg = total / 10;
    
    Serial.print("평균값 : ");
    Serial.println(avg);
    delay(1000);
    
}
