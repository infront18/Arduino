#include <LiquidCrystal_I2C.h>     //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x27, 16, 2);  //lcd 객체 선언

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Hello world");
}

void loop()
{
  
}
