#include <SoftwareSerial.h>
SoftwareSerial BT(10,11);   // 接收腳(RX), 傳送腳(TX)；接HC-06之TXD、RXD；先不要用0,1,因為USB用

char val;

void setup()
{
  Serial.begin(9600); //for arduino serial port mointor
  BT.begin(9600);
   }

void loop()
{
  if(BT.available() ) {
    val=BT.read();
    Serial.println(val);
     }
}
