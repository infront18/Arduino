#include <SPI.h>
#include <Client.h>
#include <Ethernet.h>

byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xF1, 0x67 };
char server[] = "192.168.23.93"; //접속할 서버 주소 APMSETUP이 실행중인 컴퓨터의 ip
int trig = 8;
int echo = 9;

IPAddress ip(192,168,23,100);     //아두이노에 부여하는 ip (고정ip부여함)
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);
EthernetClient client;

void setup() {
  pinMode(trig, OUTPUT);   //trig 8번핀
  pinMode(echo, INPUT); //echo 9번핀
  
  Serial.println("Sensor Ready");
  Ethernet.begin(mac, ip, gateway, subnet); //이더넷 연결 시작
  Serial.begin(9600);  //시리얼 통신 시작
  delay(1000);
  Serial.println("connecting...");
}

void loop() 
{
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  double distance = duration / 29.0 /2.0;
  
  if(distance != 0) //거리가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print("GET /run.php?"); //읽을 PHP 파일
      client.print("distance=");
      client.print(distance);    

      client.print("&&");
      
      client.println( "HTTP/1.1");
      client.println( "Host: 192.168.23.93" ); //요청n을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      
      Serial.print("distance : ");     //거리센서
      Serial.print(distance);     //거리센서
      Serial.println("Cm");
     
      Serial.println(" ");
      delay(1000);
      
      Serial.println("OK");
    }  
  }
  delay(3000); //3초에 한번씩 센서 리딩
}
