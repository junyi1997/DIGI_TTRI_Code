
#include <ESP8266WiFi.h>

const char* ssid     = "IFTTT";
const char* password = "1234567890";

const char* host = "maker.ifttt.com";  //Ifttt主機
const char* eventName   = "105103308";  //Ifttt觸發條件名稱
const char* key = "dqTARGjv_Q1zeS_-LY1TyV";  //Ifttt授權碼

int v=0;
float volt=0;
int R=0;
float R1=1000.0;
void setup() {
  Serial.begin(115200);
  //Serial.print("Connecting to ");
  //Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Serial.println("");
  //Serial.println("WiFi connected");  
  //Serial.println("IP address: ");
  
  //Serial.println(WiFi.localIP());
}

void loop() {
  //Serial.print("connecting to ");
  //Serial.println(host);
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  else{
  v = analogRead(A0); //從A0口讀取電壓，模擬埠電壓測量範圍為0-3.3V，返回的值為0-1024 
  volt = v * (3.3 / 1023.0); //將返回值換算成電壓 
  if(volt<0.02){delay(1);}//Serial.println("Max_Error")
  else if(volt>3.2){delay(1);}//Serial.println("Min_Error")  
  else
    {
      R = abs((3.3*R1/volt)-R1);//透過分壓定理將R值算出來
      delay(1000);
    }
    String url = "/trigger/";  //組合觸發網址
    url += eventName;
    url += "/with/key/";
    url += key;
    url += "?value1=";
    url += String(R);
    
    Serial.print("V："); 
    Serial.print(volt);
    Serial.println("V");
    Serial.print("R："); 
    Serial.print(R);
    Serial.println("Ω");
    //Serial.print("Requesting URL: ");
    //Serial.println(url);
    
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" + 
                 "Connection: close\r\n\r\n");
    int timeout = millis() + 5000;
    while (client.available() == 0) {
      if (timeout - millis() < 0) {
        Serial.println("Client Timeout !");
        client.stop();
        return;
      }
    }
    
    while(client.available()){  //顯示回應訊息
      String line = client.readStringUntil('\r');
      Serial.print(line);
    }
  } 
  
  Serial.println();
  Serial.println("closing connection");

  delay(999999999999999999999999999999);  //每分鐘一次
}
