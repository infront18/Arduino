#include <SoftwareSerial.h>

SoftwareSerial gpsbt(2,4);


char c = "";
String str = "";
String targetstr = "GPGGA";

void setup() {
  Serial.begin(9600);
  gpsbt.begin(9600);
  
}

void loop() {
  if(gpsbt.available())
  {
    c = gpsbt.read();
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
        
        
        gpsbt.print("위도값 : ");
        gpsbt.print(latitude);
        gpsbt.print("    ");
        gpsbt.print("경도값 : ");
        gpsbt.println(longitude);
        
       }
       str = "";
    }
    else
    {
      str += c;
    }
  }
}
