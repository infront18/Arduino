int LED = 8; 
int d = 1000;

void setup() 
{
  pinMode (LED, OUTPUT);
 
}

void loop() 
{
  digitalWrite (LED, 1);
  delay (d);
  digitalWrite (LED, 0);
  delay (d);
}
