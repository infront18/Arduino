#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>     //LiquidCrystal 라이브러리 추가 

LiquidCrystal_I2C lcd(0x3F, 16, 2);  //lcd 객체 선언
SoftwareSerial gpsSerial(2, 3);

char c = ""; // Wn 인지 구분 및 str에 저장.
String str = ""; // \n 전까지 c 값을 저장.
String targetStr = "GPGGA"; // str의 값이 NMEA의 GPGGA 값인지 타겟

void setup() {
  lcd.init(); //LCD 사용 시작
  lcd.backlight();
  lcd.print("Start GPS... ");
  gpsSerial.begin(9600);
}

void loop() {
  if(gpsSerial.available()) // gps 센서 통신 가능?
    {
      c=gpsSerial.read(); // 센서의 값 읽기
      if(c == '\n'){ // \n 값인지 구분.
        if(targetStr.equals(str.substring(1, 6))){
          lcd.println(str);

          int first = str.indexOf(",");
          int two = str.indexOf(",", first+1);
          int three = str.indexOf(",", two+1);
          int four = str.indexOf(",", three+1);
          int five = str.indexOf(",", four+1);

          String Lat = str.substring(two+1, three);
          String Long = str.substring(four+1, five);
          String Lat1 = Lat.substring(0, 2);
          String Lat2 = Lat.substring(2);
          String Long1 = Long.substring(0, 3);
          String Long2 = Long.substring(3);

          double LatF = Lat1.toDouble() + Lat2.toDouble()/60;
          float LongF = Long1.toFloat() + Long2.toFloat()/60;

          lcd.print("Lat : ");
          lcd.println(LatF, 1);
          delay(1000); 
          lcd.print("Long : ");
          lcd.println(LongF, 1);
          delay(1000); 
        }
        str = "";
      }else{ // \n 아닐시, str에 문자를 계속 더하기
        str += c;
      }
    }
}
