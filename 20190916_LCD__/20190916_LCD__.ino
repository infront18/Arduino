#include <LiquidCrystal_I2C.h> //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x3F, 16, 2); //lcd 객체 선언

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Hello world");
  delay(5000);
  lcd.clear();
  lcd.noBacklight();
}

void loop()
{

}
