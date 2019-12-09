#include <Wire.h> // I2C 라이브러리
#include "RTClib.h" // RTC 라이브러리

RTC_DS3231 myrtc; // RTC 전역 객체
//char dayOfTheWeek[7][12] = {"sunday", "monday", "tuesday", "wednesday",
//               "thursday", "friday", "saturday"};

void setup () {

   Serial.begin(9600); // Serial 통신 초기화

   Wire.begin(); // I2C에 아두이노가 마스터로 참여

   myrtc.begin(); // RTC 초기화

   myrtc.adjust(DateTime(2019, 10, 28, 12, 21, 57)); // 2019년 10월 28일 0시 0분 0초로 초기화

}

 

void loop () {
 
      DateTime now = myrtc.now(); // 현재 날짜와 시간 얻기.

      Serial.print(now.year(), DEC); //년도 출력.
      Serial.print('/');
      Serial.print(now.month(), DEC); //달 출력.
      Serial.print('/');
      Serial.print(now.day(), DEC); //일 출력.
      Serial.print(' ');
      Serial.print(now.hour(), DEC); //시간 출력.
      Serial.print(':');
      Serial.print(now.minute(), DEC); //분 출력.
      Serial.print(':');
      Serial.print(now.second(), DEC); //초 출력.

      //Serial.print(' == ');
      //Serial.println(dayOfTheWeek[now.dayOfTheWeek()]);
      
      Serial.println();

      delay(1000);

}
