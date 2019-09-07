
#include <ESP8266WiFi.h>
#define SSID    "IFTTT"                     
#define PASS    "1234567890"     

void setup()
{
  Serial.print("Connecting to ");
  Serial.println(SSID);
  WiFi.begin( SSID, PASS );
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 }
 
void loop(){

WiFiClientSecure client;
//第二組感應器就把value1=1改成value1=2
        String getStr_line = "GET /trigger/sensor_pir/with/key/dqTARGjv_Q1zeS_-LY1TyV?value1=1  HTTP/1.1\r\n";
        client.print( getStr_line );
        client.print( "Host: maker.ifttt.com\n" );
        client.print( "Connection: close\r\n\r\n" );
        client.stop();
 delay(5000);
  
}
