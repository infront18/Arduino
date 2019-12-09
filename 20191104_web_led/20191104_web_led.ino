#include <SPI.h>
#include <Ethernet.h>

#if defined(WIZ550io_WITH_MACADDRESS) //WIZ550io에 표시된 MAC 주소를 사용한다면
;
#else
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; //mac 주소 입력
#endif

IPAddress ip(192,168,23,37);  //로컬 네트워크에서 유일한 IP를 사용해야 합니다.
IPAddress gateway( 192, 168, 23, 1 );
IPAddress subnet( 255, 255, 255, 0 );
// fill in your Domain Name Server address here:
IPAddress myDns(8, 8, 8, 8); // google puble dns

EthernetServer server(80); //80은 포트번호
void check_led_status();

#define RED_PORT 5     //RED rgb 핀
#define GREEN_PORT 6   //GREEN rgb 핀
#define BLUE_PORT 7   //BLUE rgb 핀

void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ; //시리얼 포트가 연결 될 때까지 기다림, 레오나르도 경우만 필요
  }

  pinMode(RED_PORT, OUTPUT);    //RED 핀 출력 설정
  digitalWrite(RED_PORT, HIGH); //RED 핀 초기 설정으로 켜놓기
  
  pinMode(GREEN_PORT, OUTPUT);  //GREEN 핀 출력 설정
  pinMode(BLUE_PORT, OUTPUT);   //BLUE 핀 출력 설정

//이더넷 디바이스 초기화
#if defined __USE_DHCP__
#if defined(WIZ550io_WITH_MACADDRESS) //WIZ550io에 할당된 맥 주소를 사용할 경우
  Ethernet.begin();
#else
  Ethernet.begin(mac);
#endif  
#else
#if defined(WIZ550io_WITH_MACADDRESS) 
  Ethernet.begin(ip, myDns, gateway, subnet);
#else
  Ethernet.begin(mac, ip, myDns, gateway, subnet);
#endif  
#endif 

  //서버 연결 시작
  server.begin();
  Serial.println("WebServerControlLED");
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  
  //수신 클라이언트가 있는 지 확인
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    //http 요청이 빈 라인으로 끝났을 때 
    boolean currentLineIsBlank = true;
      String buffer = ""; //버퍼 선언
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
    buffer += c;    //버퍼 할당
        Serial.write(c);
        
        if (c == '\n' && currentLineIsBlank) {
          //표준 http 응답 헤더 전송 시작
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          
          //본문(상황에 맞는 웹 페이지) 전달
          //client.println("<!DOCTYPE HTML>");, HTML5 사용시
          client.println("<html>");  //웹 페이지 작성은 HTML사용
          client.println("<body>");

          //LED에 상황을 판단한후 상태를 알림
    if (digitalRead(RED_PORT)>0) {   //빨간 불이면
            client.println("LED is <font color='red'>RED</font>"); //웹페이지에 LED is RED라고 표시, RED는 빨간색
          } else if (digitalRead(GREEN_PORT)>0) { 
            client.println("LED is <font color='green'>GREEN</font>");
          } else if (digitalRead(BLUE_PORT)>0) {
            client.println("LED is <font color='blue'>BLUE</font>");
          } else {
            client.println("LED is <font color='black'>OFF</font>");
          }

          //색 선택 부분 만들기
          client.println("<br />");
          client.println("<FORM method=\"get\" action=\"/led.cgi\">");
          client.println("<P> <INPUT type=\"radio\" name=\"status\" value=\"1\">RED");
          client.println("<P> <INPUT type=\"radio\" name=\"status\" value=\"2\">GREEN");
          client.println("<P> <INPUT type=\"radio\" name=\"status\" value=\"3\">BLUE");
          client.println("<P> <INPUT type=\"radio\" name=\"status\" value=\"0\">OFF");
          client.println("<P> <INPUT type=\"submit\" value=\"Submit\"> </FORM>");

          client.println("</body>");
          client.println("</html>");
          break;
        }
        if (c == '\n') {          
          currentLineIsBlank = true;
      buffer="";
        } 
        else if ( c == '\r') {
          //빨간 불을 선택하면
    if(buffer.indexOf("GET /led.cgi?status=1")>=0){
      //빨간 불 킴
      digitalWrite(RED_PORT, HIGH);
            digitalWrite(GREEN_PORT, LOW);
            digitalWrite(BLUE_PORT, LOW);

            //두번째 페이지 전송
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
      client.println("<html>");
      client.println("<body>");

      if (digitalRead(RED_PORT)>0) {
              client.println("LED is <font color='red'>RED</font>");
            } else if (digitalRead(GREEN_PORT)>0) { 
              client.println("LED is <font color='green'>GREEN</font>");
            } else if (digitalRead(BLUE_PORT)>0) {
              client.println("LED is <font color='blue'>BLUE</font>");
            } else {
              client.println("LED is <font color='black'>OFF</font>");
            }

            client.println("<br />");
      client.println("<a href=\"/led.htm\">Go to control-page</a>"); //다시 처음 페이지로 

      client.println("</body>");
      client.println("</html>");
      currentLineIsBlank = false;
      break;
     }

           //초록을 선택하면
           if(buffer.indexOf("GET /led.cgi?status=2")>=0){
       //초록 핀 킴
       digitalWrite(RED_PORT, LOW);
             digitalWrite(GREEN_PORT, HIGH);
             digitalWrite(BLUE_PORT, LOW);
      
             client.println("HTTP/1.1 200 OK");
             client.println("Content-Type: text/html");
       client.println();
       client.println("<html>");
       client.println("<body>");
               
       if (digitalRead(RED_PORT)>0) {
               client.println("LED is <font color='red'>RED</font>");
             } else if (digitalRead(GREEN_PORT)>0) { 
               client.println("LED is <font color='green'>GREEN</font>");
             } else if (digitalRead(BLUE_PORT)>0) {
               client.println("LED is <font color='blue'>BLUE</font>");
             } else {
               client.println("LED is <font color='black'>OFF</font>");
             }

       client.println("<br />");
       client.println("<a href=\"/led.htm\">Go to control-page</a>");

       client.println("</body>");
       client.println("</html>");
       currentLineIsBlank = false;
       break;
      }

            //파란 색을 선택하면
            if(buffer.indexOf("GET /led.cgi?status=3")>=0){
        digitalWrite(RED_PORT, LOW);
              digitalWrite(GREEN_PORT, LOW);
              digitalWrite(BLUE_PORT, HIGH);
        
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();
        client.println("<html>");
        client.println("<body>");
               
        if (digitalRead(RED_PORT)>0) {
                client.println("LED is <font color='red'>RED</font>");
              } else if (digitalRead(GREEN_PORT)>0) { 
                client.println("LED is <font color='green'>GREEN</font>");
              } else if (digitalRead(BLUE_PORT)>0) {
                client.println("LED is <font color='blue'>BLUE</font>");
              } else {
                client.println("LED is <font color='black'>OFF</font>");
              }

        client.println("<br />");
        client.println("<a href=\"/led.htm\">Go to control-page</a>");

        client.println("</body>");
        client.println("</html>");
        currentLineIsBlank = false;
        break;
      }

            //off를 선택했을 때
      if(buffer.indexOf("GET /led.cgi?status=0")>=0){
        digitalWrite(RED_PORT ,LOW);
              digitalWrite(GREEN_PORT, LOW);
              digitalWrite(BLUE_PORT, LOW);
        
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
          client.println();
        client.println("<html>");
        client.println("<body>");
                
        if (digitalRead(RED_PORT)>0) {
                client.println("LED is <font color='red'>RED</font>");
              } else if (digitalRead(GREEN_PORT)>0) { 
                client.println("LED is <font color='green'>GREEN</font>");
              } else if (digitalRead(BLUE_PORT)>0) {
                client.println("LED is <font color='blue'>BLUE</font>");
              } else {
                client.println("LED is <font color='black'>OFF</font>");
              }

        client.println("<br />");
        client.println("<a href=\"/led.htm\">Go to control-page</a>");

        client.println("</body>");
        client.println("</html>");
        currentLineIsBlank = false;
        break;
      }
  } else{ //if( c != '\r') {

          currentLineIsBlank = false;
        }
      }
    }
   
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}
