#include <SoftwareSerial.h>
#include <Wire.h>
int BT_Pin=4;
SoftwareSerial BT(2,3); 
void setup() {
  BT.begin(9600);   
  Serial.begin(9600);
  pinMode(BT_Pin,INPUT);
}
void loop() {
  int BTStat=0; 
  while(true){
    if(digitalRead(BT_Pin)==1){
      delay(10);
      if(BTStat==0){
        BTStat=1;
        BT.print("0");
        Serial.println("0");
      }
    }else{
      if(BTStat==1){
        BTStat=0;
        BT.print("1");
        Serial.println("1");
        delay(10);
      }
    }
  }
}
