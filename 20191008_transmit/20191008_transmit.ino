#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

const int buttonPin = 4;
const int khz = 38;

IRsend irsend;

unsigned int light_onoff_signal_buf[] = { 3550, 1750, 600, 400, 600, 1800, 550, 450, 600, 450, 600, 1800, 550, 450, 600, 450, 600, 500, 600, 450, 600, 400, 650, 400, 550 };

void setup() 
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() 
{
  int buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
  {
    
  }
  else
  {
    Serial.println("Sent");
    irsend.sendRaw(light_onoff_signal_buf, sizeof(light_onoff_signal_buf) / sizeof(int), khz);
  }

  delay(1000);
}
