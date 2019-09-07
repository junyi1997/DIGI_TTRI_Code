int pinoTouchOn[] = {4,13,12,14,27,32,33,15}; //pino com sensor touch (pode-se usar a constante nativa T0)
int state[]={0,0,0,0,0,0,0,0};
int pinoTouchBlink = 2; //pino com sensor touch (pode-se usar a constante nativa T4)
int capacitanciaMaxima = 45; //valor que nos da a certeza de toque (ache esse valor através da calibragem)
#include <BluetoothSerial.h>
BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT
void setup()
{
   Serial.begin(115200);
   delay(1000);
   SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得
   
}
void loop()
{
  for (int j =0 ; j<8;j++){Serial.print(j);Serial.print("  ");Serial.println(touchRead(pinoTouchOn[j]));}
  //Serial.println(touchRead(pinoTouchBlink));
  int mediaT0[] = {0,0,0,0,0,0,0,0};
  int mediaT4 = 0;

  for(int i=0; i< 100; i++)
  {
    for (int j =0 ; j<8;j++){mediaT0[j] += touchRead(pinoTouchOn[j]);}
    mediaT4 += touchRead(pinoTouchBlink);
  }
  for (int j=0 ; j<8;j++){mediaT0[j] = mediaT0[j] / 100;;} 
  mediaT4 = mediaT4 / 100;

  if(mediaT0[0] < capacitanciaMaxima-10)
  {
    if(state[0]==0)
    {
      state[0]=1;
      Serial.println("Do0");SerialBT.print("Do0");
    }
  }else{
    if(state[0]==1)
    {
      state[0]=0;
      SerialBT.print("000");
    }
  }
  if(mediaT0[1] < capacitanciaMaxima)
  {
    if(state[1]==0)
    {
      state[1]=1;
      Serial.println("Re0");SerialBT.print("Re0");
    }
  }else{
    if(state[1]==1)
    {
      state[1]=0;
      SerialBT.print("000");
    }
  }
  if(mediaT0[2] < capacitanciaMaxima)
  {
    if(state[2]==0)
    {
      state[2]=1;
      Serial.println("Mi0");SerialBT.print("Mi0");
    }
  }else{
    if(state[2]==1)
    {
      state[2]=0;
      SerialBT.print("000");
    }
  }
  if(mediaT0[3] < capacitanciaMaxima)
  {
    if(state[3]==0)
    {
      state[3]=1;
      Serial.println("Fa0");SerialBT.print("Fa0");
    }
  }else{
    if(state[3]==1)
    {
      state[3]=0;
      SerialBT.print("000");
    }
  }
  if(mediaT0[4] < capacitanciaMaxima)
  {
    if(state[4]==0)
    {
      state[4]=1;
      Serial.println("So0");SerialBT.print("So0");
    }
  }else{
    if(state[4]==1)
    {
      state[4]=0;
      SerialBT.print("000");
    }
  }
  if(mediaT0[5] < capacitanciaMaxima)
  {
    if(state[5]==0)
    {
      state[5]=1;
      Serial.println("La0");SerialBT.print("La0");
    }
  }else{
    if(state[5]==1)
    {
      state[5]=0;
      SerialBT.print("000");
    }
  }
  if(mediaT0[6] < capacitanciaMaxima)
  {
    if(state[6]==0)
    {
      state[6]=1;
      Serial.println("Si0");SerialBT.print("Si0");
    }
  }else{
    if(state[6]==1)
    {
      state[6]=0;
      SerialBT.print("000");
    }
  }
  if(mediaT0[7] < capacitanciaMaxima)
  {
    if(state[7]==0)
    {
      state[7]=1;
      Serial.println("Do1");SerialBT.print("Do1");
    }
  }else{
    if(state[7]==1)
    {
      state[7]=0;
      SerialBT.print("000");
    }
  }
  

}
