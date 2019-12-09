#include <DHT.h>
#include <EtherCard.h>
#include <SPI.h>
#include <Client.h>


#define DHTPIN 2        //디지털 2번 핀 사용
#define DHTTYPE DHT11   // DHT11 사용
byte mac[] = { 0x90, 0xA2, 0xDA, 0x0E, 0xF1, 0x67 };
char server[] = "192.168.23.47"; //접속할 서버 주소 APMSETUP이 실행중인 컴퓨터의 ip

IPAddress ip(192,168,23,60);     //아두이노에 부여하는 ip (고정ip부여함)
IPAddress gateway(192,168,23,1);
IPAddress subnet(255,255,255,0);
EthernetClient client;
DHT dht(DHTPIN, DHTTYPE);  //DHT 라이브러리에 포함된 함수 형태정의


void setup() {
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
  if(humidity!=0 && temperature!=0) //온습도가 0이면 MYSQL에 값 보내지 마
  {
    if (client.connect(server, 80)) {   // Http 요청 헤더
      client.print( "GET /test6.php?"); //읽을 PHP 파일
      client.print("humidity=");
      client.print( humidity );
      client.print("&&");
      client.print("temperature=");
      client.print( temperature );      //여기까지는 PHP에서 받기로한 데이터들이다
      client.println( " HTTP/1.1");
      client.println( "Host: 192.168.23.47" ); //요청을 보낼 서버의 주소
      client.println( "Content-Type: application/x-www-form-urlencoded" );   
      client.println( "Connection: close" );
      client.println();
      client.stop();
      Serial.print("Current humdity = "); 
      Serial.print(humidity);
      Serial.print("%  ");
      Serial.print("temperature = ");
      Serial.print(temperature);
      Serial.println("C  ");
      Serial.println("OK");
    }  
  }
  delay(5000); //5초에 한번씩 센서 리딩
}

-php-
<?php
  //php info
  $mysql_hostname = '192.168.23.47';
  $mysql_username = 'phpmyadmin';
  $mysql_password = 'polo1018';
  $mysql_database = 'nodemcu';

  //DB연결
  $connect = new mysqli($mysql_hostname, $mysql_username, $mysql_password, $mysql_database);
  //DB연결 확인
  if($connect->connect_errno){
 echo '[연결실패] : '.$connect->connect_error.'<br>';
  } else {
 echo '[연결성공]<br>';
  }
   $humidity = $_GET['humidity'];         //습도 읽어와
   $temperature = $_GET['temperature'];   //온도 읽어와
   $sql = "INSERT INTO dht(temperature, humidity) VALUES($temperature, $humidity)";
 
   if($humidity!=0){    //온습도 값을 DB에 삽입하는 쿼리
    $query = "insert into temp(humidity, temperature) values('$humidity', '$temperature')";
    $connect->query($query);  //쿼리실행
   }
 
   do {  //맨 마지막 레코드를 읽는 쿼리
 $query3 = "select * from temp order by no desc limit 1;";
    $result = $connect->query($query3);  //쿼리실행
    $row = mysqli_fetch_object($result); //실행된 쿼리값을 읽음
   } while($row->humidity == 0);

   echo date("Y-m-d H:i:s") . "<br />\n";  //날짜와 시간 표시
   echo "$row->no  ";
   echo "$row->humidity  ";
   echo "$row->temperature";
   /* if($row->temperature>27) { //온도가 27도 넘으면 경보음 울림(로컬 컴퓨터 하단경로에 MP3파일 넣을 것)
   echo '<embed src="c:\test.mp3" loop=-1> </embed>';  
   }
   */

 //하단 자바스크립트: 웹페이지 자동 REFRESH기능
?>
<script language='javascript'>
  window.setTimeout('window.location.reload()',6000); //1초마다 리플리쉬 시킨다 1000이 1초가 된다.
</script>
