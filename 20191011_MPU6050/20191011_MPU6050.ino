#include <Wire.h>

const int MPU_Address = 0x68;

int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
void setup() 
{
  Wire.begin();
  Wire.beginTransmission(MPU_Address);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
  Serial.begin(9600);
}

void loop() 
{
  Wire.beginTransmission(MPU_Address);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_Address,14);

  AcX = Wire.read() << 8 | Wire.read(); 
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();
  Tmp = Wire.read() << 8 | Wire.read();
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();
  GyZ = Wire.read() << 8 | Wire.read();
  
  Serial.print(" 가속도X  = ");  Serial.print(AcX);
  Serial.print(" 가속도Y  = ");  Serial.print(AcY);
  Serial.print(" 가속도Z  = ");  Serial.print(AcZ);

  
 Serial.print(" 온도 = ");Serial.print  (Tmp / 340.00 + 36.53);
 Serial.print(" 자이로X  = ") ;Serial.print (GyX);
 Serial.print(" 자이로Y = ");Serial.print   (GyY);
 Serial.print(" 자이로z = ");Serial.println (GyZ);
 Serial.println("                  ");

 Wire.endTransmission();

 delay(1000);
}
