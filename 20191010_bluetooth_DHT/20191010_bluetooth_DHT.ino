#include <SoftwareSerial.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11

SoftwareSerial mybluetooth(2, 3);
DHT mydht(8, DHT11);

void setup() {
  mydht.begin();
  mybluetooth.begin(9600);
  delay(2000);
}

void loop() {
  float temp = mydht.readTemperature();
  float humi = mydht.readHumidity();

  mybluetooth.print("온도값 : ");
  mybluetooth.print(temp);
  mybluetooth.print("    ");
  mybluetooth.print("습도값 : ");
  mybluetooth.println(humi);
  delay(500);
}
