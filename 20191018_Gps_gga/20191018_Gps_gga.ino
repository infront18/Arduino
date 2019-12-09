#include <SoftwareSerial.h>

SoftwareSerial gps(2,3);
String sentence ="";
boolean process_sentence = false;

void setup() 
{
  Serial.begin(9600);
  gps.begin(9600);

}

void loop() {
  if(gps.available())
  {
    char data = gps.read();
    switch(data)
    {
      case '\n':
          break;
      case '\r':
          process_sentence = true;
          break;
      default:
          sentence = sentence +data;
          break;  
    }
  }

  if(process_sentence)
  {
    process_sentence = false;
    if(sentence.startsWith("$GPGGA"))
      Serial.println(sentence);
      
      sentence = "";
  }

}
