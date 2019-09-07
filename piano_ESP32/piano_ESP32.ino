#include <BluetoothSerial.h>
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT
int BT_Pin=4;
void setup() {
  SerialBT.begin("E_PON_Violin");//<<藍芽名稱，請自己記得   
  Serial.begin(9600);
  pinMode(BT_Pin,INPUT);
}
void loop() {
  int BTStat=0; 
  while(true){
    if(digitalRead(BT_Pin)==1){
      delay(750);
      BTStat=1;
      SerialBT.print("0");
      Serial.println("0");
    }else{
      if(BTStat==1){
        BTStat=0;
        SerialBT.print("1");
        Serial.println("1");
        delay(10);
      }
    }
  }
}
