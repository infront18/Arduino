#include <LiquidCrystal_I2C.h> //LiquidCrystal 라이브러리 추가 
LiquidCrystal_I2C lcd(0x3F, 16, 2); //lcd 객체 선언

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(12, INPUT); // echopin
  pinMode(13, OUTPUT); //triggerpin
  pinMode(7, OUTPUT); //진동센서
}

int distance;

void loop()
{
  digitalWrite(13, HIGH);
  delayMicroseconds(10);
  digitalWrite(13, LOW);

  distance = pulseIn(12, HIGH) / 58;
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);

  lcd.setCursor(0, 0);
  lcd.print("dist:");
  lcd.print(distance);
  lcd.print("cm");
  delay(1000);
  lcd.clear();

  if (distance > 0 && distance <= 10)
  {
    digitalWrite(7, HIGH);
  }
  else
  {
    digitalWrite(7, LOW);
  }
}
