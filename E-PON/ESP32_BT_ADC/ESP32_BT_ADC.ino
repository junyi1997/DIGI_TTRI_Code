int pinADC[]={36, 39, 34, 35, 32, 33};//25, 26, 27, 14, 12, 13, 4, 0, 2, 15
int state[]={0,0,0,0,0,0,0,0};
int small_R=3900;
int big_R=1365;
#include <driver/adc.h>
#include <BluetoothSerial.h>
#include <WiFi.h>
#include "esp32-hal-adc.h" 
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT
void setup()
{
  for (int i=0; i<8; i++){pinMode(pinADC[i], INPUT);}
  Serial.begin(9600);//序列視窗
  SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得
}
void loop()
{
  if (analogRead(pinADC[0])<small_R && analogRead(pinADC[0])>big_R)
  {
    if(state[0]==0)
    {
      state[0]=1;
      //Serial.println("Do0");
      SerialBT.print("Do0");
    }
  }else{
    if(state[0]==1)
    {
      state[0]=0;
      SerialBT.print("000");
    }
  }
 
  if (analogRead(pinADC[1])<small_R && analogRead(pinADC[1])>big_R)
  {
    if(state[1]==0)
    {
      state[1]=1;
      //Serial.println("Re0");
      SerialBT.print("Re0");
    }
  }else{
    if(state[1]==1)
    {
      state[1]=0;
      SerialBT.print("000");
    }
  }
  
  if (analogRead(pinADC[2])<small_R && analogRead(pinADC[2])>big_R)
  {
    if(state[2]==0)
    {
      state[2]=1;
      //Serial.println("Mi0");
      SerialBT.print("Mi0");
    }
  }else{
    if(state[2]==1)
    {
      state[2]=0;
      SerialBT.print("000");
    }
  }
  
  if (analogRead(pinADC[3])<small_R && analogRead(pinADC[3])>big_R)
  {
    if(state[3]==0)
    {
      state[3]=1;
      //Serial.println("Fa0");
      SerialBT.print("Fa0");
    }
  }else{
    if(state[3]==1)
    {
      state[3]=0;
      SerialBT.print("000");
    }
  }
  
  if (analogRead(pinADC[4])<small_R && analogRead(pinADC[4])>big_R)
  {
    if(state[4]==0)
    {
      state[4]=1;
      //Serial.println("So0");
      SerialBT.print("So0");
    }
  }else{
    if(state[4]==1)
    {
      state[4]=0;
      SerialBT.print("000");
    }
  }
 
  if (analogRead(pinADC[5])<small_R && analogRead(pinADC[5])>big_R)
  {
    if(state[5]==0)
    {
      state[5]=1;
      //Serial.println("La0");
      SerialBT.print("La0");
    }
  }else{
    if(state[5]==1)
    {
      state[5]=0;
      SerialBT.print("000");
    }
  }
  int read_raw1 ;
  adc2_config_channel_atten( ADC2_CHANNEL_8, ADC_ATTEN_6db );
  esp_err_t r = adc2_get_raw( ADC2_CHANNEL_8, ADC_WIDTH_12Bit, &read_raw1);
  //Serial.println(read_raw1);
  int read_raw2 ;
  adc2_config_channel_atten( ADC2_CHANNEL_9, ADC_ATTEN_6db );
  esp_err_t r1 = adc2_get_raw( ADC2_CHANNEL_9, ADC_WIDTH_12Bit, &read_raw2);
  //Serial.println(read_raw2);
  if(read_raw1>big_R&&read_raw1<small_R)
  {
    if(state[6]==0)
    {
      state[6]=1;
      //Serial.println("Si0");
      SerialBT.print("Si0");
    }
  }else{
    if(state[6]==1)
    {
      state[6]=0;
      SerialBT.print("000");
    }
  }
  if(read_raw2>big_R&&read_raw2<small_R)
  {
    if(state[7]==0)
    {
      state[7]=1;
      //Serial.println("Do1");
      SerialBT.print("Do1");
    }
  }else{
    if(state[7]==1)
    {
      state[7]=0;
      SerialBT.print("000");
    }
  }
  
  delay(10);
}
