#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3f, 16,2);
const int MPU_Address = 0x68;

int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
void setup() 
{
  lcd.init();
  lcd.backlight();
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
  
 Tmp = Wire.read() << 8 | Wire.read();
 
 lcd.setCursor(0,0); // LCD Cursor 원점
 lcd.print("Temp: ");
 lcd.print(Tmp / 340.00 + 36.53,1);
 lcd.print("C");
 Wire.endTransmission();

 delay(2000);
}
