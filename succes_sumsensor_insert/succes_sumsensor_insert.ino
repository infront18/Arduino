#include "DHT.h"  //DHT 온습도 센서 라이브러리 사용
#include <SPI.h>
#include <Client.h>
#include <Ethernet.h>

#define DHTPIN 2        //디지털 2번 핀 사용
#define DHTTYPE DHT11   // DHT11 사용
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xF1, 0x67 };
char server[] = "192.168.23.43"; //접속할 서버 주소 APMSETUP이 실행중인 컴퓨터의 ip


IPAddress ip(192,168,23,45);     //아두이노에 부여하는 ip (고정ip부여함)
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);
EthernetClient client;
DHT dht(DHTPIN, DHTTYPE);  //DHT 라이브러리에 포함된 함수 형태정의

void setup() {
  pinMode(A0,INPUT);   //수위센서   
  pinMode(A1,INPUT);   //조도센서   
  dht.begin();  //온습도 센서 동작시작
  Serial.println("Sensor Ready");

  Ethernet.begin(mac, ip, gateway, subnet); //이더넷 연결 시작
  Serial.begin(9600);  //시리얼 통신 시작
  delay(1000);
  Serial.println("connecting...");
}

void loop() {
  int humidity = dht.readHumidity();         //습도 읽어
  int temperature = dht.readTemperature();   //온도 읽어
  int waterlevel = analogRead(A0);  // 수분센서의 신호를 측정합니다.
  int brightness = analogRead(A1);   // 조도센서 연결
  if(humidity!=0 && temperature!=0) //온습도가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print( "GET /insert.php?"); //읽을 PHP 파일
      client.print("humidity=");
      client.print( humidity );
      
      client.print("&&");
      
      client.print("temperature=");
      client.print( temperature );      //여기까지는 PHP에서 받기로한 데이터들이다

      client.print("&&");
  
      client.print("waterlevel=");
      client.print( waterlevel );     

      client.print("&&");

      client.print("brightness=");
      client.print( brightness );
      
      client.println( " HTTP/1.1");
      client.println( "Host: 192.168.23.43" ); //요청을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("Current humdity = "); 
      Serial.print(humidity);
      Serial.print("%  ");
      
      Serial.print("temperature = ");
      Serial.print(temperature);
      Serial.println("℃  ");
      
      Serial.print ("waterlevel : ");     //수분센서
      Serial.println (waterlevel);     //수분센서
      
      Serial.print("brightness : ");    //조도센서
      Serial.println(brightness); //  조도센서
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(60000); //1분에 한번씩 센서 리딩
}
