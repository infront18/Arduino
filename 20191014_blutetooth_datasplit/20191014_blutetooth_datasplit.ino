#include <SoftwareSerial.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#include <Wire.h>

SoftwareSerial mybluetooth(2, 3);
DHT mydht(8, DHT11);

void setup() {
  mydht.begin();
  mybluetooth.begin(9600);
  delay(2000);
}

char data[7] = {0, }; //byte : 온도값 3byte, 습도값 3byte

void loop() {
  int temp = mydht.readTemperature();
  int humi = mydht.readHumidity();

  sprintf(data, "%03d%03d", temp, humi);

  mybluetooth.print(data);

  delay(1000);
}
