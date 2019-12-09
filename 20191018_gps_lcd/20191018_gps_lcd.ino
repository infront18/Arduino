#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C lcd (0x3F, 16, 2);
SoftwareSerial gps(2,3);

char c = "";
String str = "";
String targetstr = "GPGGA";

void setup() {
  Serial.begin(9600);
  gps.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if(gps.available())
  {
    c = gps.read();
    if( c == '\n')
    {
      if(targetstr.equals(str.substring(1,6)))
      {
        int first = str.indexOf (",");
        int two = str.indexOf (",", first + 1);
        int third = str.indexOf (",", two + 1);
        int four = str.indexOf (",", third + 1);
        int five = str.indexOf (",", four + 1);

        String lati = str.substring ( two + 1 , third);
        String longi = str.substring (four + 1 , five);

        String lati1 = lati.substring (0,2);
        String lati2 = lati.substring (2);
        String longi1 = longi.substring (0,3);
        String longi2 = longi.substring (3);

        double latitude = lati1.toDouble() + lati2.toDouble() / 60;
        double longitude = longi1.toDouble() + longi2.toDouble() / 60;

        Serial.println (latitude, 2);
        Serial.println (longitude, 2);
        Serial.println ("         ");
        
        lcd.setCursor(4,0);
        lcd.print(latitude, 7);
        lcd.setCursor(4,1);
        lcd.print(longitude, 7);
        //lcd.clear();            // 글자를 모두 지워라.
        delay(1000);            // 1초 대기
       }
       str = "";
    }
    else
    {
      str += c;
    }
  }
}
