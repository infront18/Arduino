#include <Wire.h> // Wire.h 호출 I2C통신 관련 함수  
#include <VL6180X.h> // VL6180X.h 호출 VL6180 관련 함수 

VL6180X sensor;

void setup() 
{
  Serial.begin(9600); // Serial 모니터 9600 보드레이트 설정 
  Wire.begin(); // I2C 통신 초기화 
  pinMode(7, OUTPUT);
  
  sensor.init(); // VL61480 센서 초기화 함수 호출 
  sensor.configureDefault(); //센서 기본 설정 함수 호출
  sensor.setTimeout(500); // 센서가 동작 준비되지 않은 경우 대기시간 설정 
}

void loop() 
{ 
  if (sensor.timeoutOccurred())
  { 
    Serial.print(" TIMEOUT"); 
    }// 마지막 호출 이후에 읽기 시간 초과가 발생 했는지 여부를 확인
    
  int range = sensor.readRangeSingleMillimeters(); // 센서 데이터호출 후 int 형 range에 저장 
  if(range < 255)
       digitalWrite(7, HIGH); 
  else
       digitalWrite(7, LOW); 
  
  Serial.print("range : ");
  Serial.print(range); // Serial 모니터에 출력 "range : 데이터 값 "
  Serial.println(); // Serial 입력줄 내리기 
  delay(1000);
} 
