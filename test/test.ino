

char ssid[] = "sanhak01";     //  your network SSID (name)
char pass[] = "doowonsh";    // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status
WiFiClient client;
char server[] = "192.168.23.29";

const int HumPin = 7;
const int TempPin = A2;


void setup() {
  Serial.begin(9600);

  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA2 network...");
  status = WiFi.begin(ssid, pass);

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) {
    Serial.println("Couldn't get a wifi connection");
    while (true);
  }
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
    IPAddress ip = WiFi.localIP();
    Serial.print("IP address is : ");
    Serial.println(ip);
    Serial.println("");
  }
}


void loop() {
  int HumVal = analogRead(HumPin);
  int TempVal = analogRead(TempPin);

  float HumVoltage = (HumVal / 1024.0) * 5.0;
  float TempVoltage = (TempVal / 1024.0) * 5.0;

  float Hum = -12.5 + (125 * (HumVoltage / 5.0));
  float Temp = -66.875 + (218.75 * (TempVoltage / 5.0));
  float FTemp = -88.375 + (393.75 * (TempVoltage / 5.0));

  char CharHum[5];
  char CharTemp[5];
  char CharFTemp[5];

  dtostrf(Hum, 5, 2, CharHum);
  dtostrf(Temp, 5, 2, CharTemp);
  dtostrf(FTemp, 5, 2, CharFTemp);

  if(client.connect(server,80)){
    Serial.println("Connected...");
    client.print("GET /temp_rec.php?");
    client.print("hum=");
    client.print(Hum);
    client.print("&&");
    client.print("temp=");
    client.print(Temp);
    client.print("&&");
    client.print("ftemp=");
    client.print(FTemp);
    client.println(" HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
    client.println();
    Serial.println("Transfer terminated");
    delay(2000);
  }else{
    delay(1000);
    Serial.println("Connection failed");
    delay(2000);
  }
  delay(1000);
  client.stop();

  delay(2000);

  Serial.print("Temperature (C) is : ");
  Serial.println(CharTemp);
  Serial.print("Temperature (F) is : ");
  Serial.println(CharFTemp);
  Serial.print("Humidity (%) is : ");
  Serial.println(CharHum);
  Serial.println("");
  
  delay(55000);  
}
