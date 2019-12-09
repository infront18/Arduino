#include <AudioFrequencyMeter.h>

//#include <MaxMatrix.h>


  //#include <LedControl.h>
  
  #include <SoftwareSerial.h>
  
  
  
  
  
  
  SoftwareSerial mybluetooth (2, 3);    //Tx -> 2, Rx -> 3
  AudioFrequencyMeter mydm = AudioFrequencyMeter(); // 12번 din /11번 clk /10번 cs/
  
  
  byte a[] = {B00010000,B00110000,B00010000,B00010000,B00010000,B00010000,B00010000,B00111000};  
  byte b[] = {B00111000,B01000100,B00000100,B00000100,B00001000,B00010000,B00100000,B01111100};
  byte c[] = {B00111000,B01000100,B00000100,B00011000,B00000100,B00000100,B01000100,B00111000};
  byte d[] = {B00000100,B00001100,B00010100,B00100100,B01000100,B01111100,B00000100,B00000100};
  byte e[] = {B01111100,B01000000,B01000000,B01111000,B00000100,B00000100,B01000100,B00111000};
  byte f[] = {B00111000,B01000100,B01000000,B01111000,B01000100,B01000100,B01000100,B00111000};
  byte g[] = {B01111100,B00000100,B00000100,B00001000,B00010000,B00100000,B00100000,B00100000};
  byte h[] = {B00111000,B01000100,B01000100,B00111000,B01000100,B01000100,B01000100,B00111000};
  byte i[] = {B00111000,B01000100,B01000100,B01000100,B00111100,B00000100,B01000100,B00111000};
  byte j[] = {B10010010,B01010100,B00111000,B11101111,B00111000,B01010100,B10010010,B00000000};
  byte k[] = {B00111000,B01000100,B01000100,B01000100,B01000100,B01000100,B01000100,B00111000};
  byte l[] = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
              
  void setup() 
  {
   //mydm.shutdown(0,false);
   mydm.setIntensity(0, 3); // 센서 밝기
   mydm.clearDisplay(0);
   pinMode(7, OUTPUT); 
   mybluetooth.begin (9600);
  }
    
  void loop() 
  {
    if( mybluetooth.read() == '1') 
       {
          A();
       } 
    else if(mybluetooth.read() == '2')
       {
          B();
       }
    else if(mybluetooth.read() == '3')
       {
          C();
       }
   else if(mybluetooth.read() == '4')
       {
          D();
       }
   else if(mybluetooth.read() == '5')
       {
          E();
       }    
   else if(mybluetooth.read() == '6')
       {
          F();
       }      
   else if(mybluetooth.read() == '7')
       {
          G();
       }   
  else if(mybluetooth.read() == '8')
       {
          H();
       }     
  else if(mybluetooth.read() == '9')
       {
          I();
       }    
  else if(mybluetooth.read() == '*')
       {
          J();
       }      
  else if(mybluetooth.read() == '0')
       {
          K();
       }  
  else if(mybluetooth.read() == '#')
       {
          L();
       }                 
  }

  void A()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, a[n]);
       }
   }
   
    void B()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, b[n]);
       }
   }
   
    void C()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, c[n]);
       }
   }
   
    void D()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, d[n]);
       }
   }
   
    void E()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, e[n]);
       }
   }
     void F()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, f[n]);
       }
   }
     void G()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, g[n]);
       }
   }
     void H()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, h[n]);
       }
   }
     void I()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, i[n]);
       }
   }
     void J()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, j[n]);
       }
   }
     void K()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, k[n]);
       }
   }
     void L()
   {
      for (int n = 0; n < 8; n++)
       {
         mydm. setRow (0, n, l[n]);
       }  
   }
   
