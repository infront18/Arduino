#include <LedControl.h>

LedControl mydm = LedControl(12, 11, 10, 1); 
//12 : din, 11 : clk, 10 : cs

byte a[] = {B00000000, 
            B00100100, 
            B01111110, 
            B11111111, 
            B11111111, 
            B01111110, 
            B00111100, 
            B00011000};
            
byte b[] = {B00011000, 
            B00111100, 
            B01111110, 
            B11000011, 
            B00111100, 
            B01111110, 
            B11000011, 
            B10000001};
            
byte c[] = {B00111100, 
            B00111100, 
            B00011000, 
            B01111110, 
            B01011010, 
            B00011000, 
            B00111100, 
            B00100100};

void setup() 
{
  mydm.shutdown(0, false);
  mydm.setIntensity(0, 5);
  mydm.clearDisplay(0);
}

void A()
{
  for (int i=0; i<8; i++)
  {
    mydm.setRow (0, i, a[i]);
  }
}

void B()
{
  for (int i=0; i<8; i++)
  {
    mydm.setRow (0, i, b[i]);
  }
}

void C()
{
  for (int i=0; i<8; i++)
  {
    mydm.setRow (0, i, c[i]);
  }
}

void loop()
{
  A();
  delay(2000);
  
  B();
  delay(2000);
  
  C();
  delay(2000);
}
