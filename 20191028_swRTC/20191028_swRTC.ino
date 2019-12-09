#include <core_build_options.h>
#include <swRTC.h>

swRTC myrtc;

void setup() {
  myrtc.stopRTC();
  myrtc.setTime(11, 30,00);
  myrtc.setDate(28, 10, 2019);
  myrtc.startRTC();
  Serial.begin(9600);
}

void loop() {
    Serial.print(myrtc.getHours(), DEC);
    Serial.print(":");
    Serial.print(myrtc.getMinutes(), DEC);
    Serial.print(":");
    Serial.print(myrtc.getSeconds(), DEC);
    
    Serial.print(" -- ");
    
    Serial.print(myrtc.getYear(), DEC);
    Serial.print("/");
    Serial.print(myrtc.getMonth(), DEC);
    Serial.print("/");
    Serial.print(myrtc.getDay(), DEC);

    Serial.print("(Leapyear : ");
    if(myrtc.isLeapYear())
      Serial.print("YES");
    else
      Serial.print("NO");
    
    Serial.println(")");

    Serial.print("Day of week : ");
    Serial.println(myrtc.getWeekDay(), DEC);
    
    
    delay(3000);
      
}
