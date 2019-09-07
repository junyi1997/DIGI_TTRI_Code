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
  int channel[]={ADC2_CHANNEL_8,ADC2_CHANNEL_9};
  int read_raw[2] ;
  adc2_config_channel_atten( &channel, ADC_ATTEN_6db );
  esp_err_t r = adc2_get_raw( &channel, ADC_WIDTH_12Bit, &read_raw);
  Serial.println(read_raw1);
  adc2_config_channel_atten( &channel, ADC_ATTEN_6db );
  esp_err_t r1 = adc2_get_raw( &channel, ADC_WIDTH_12Bit, &read_raw);
  Serial.println(read_raw2);
}
