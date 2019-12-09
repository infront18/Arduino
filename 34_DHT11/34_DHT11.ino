#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11


void setup() {
  mydht.begin();
  Serial.begin(9600); //시리얼 통신을 시작하며, 통신속도는 9600
}

void loop() {
  float temp = mydht.readTemperature();
  float humi = mydht.readHumidity();

  Serial.print("온도값 : ");
  Serial.print(temp);
  Serial.print("    ");
  Serial.print("습도값 : ");
  Serial.println(humi);
  delay(1000);
}
