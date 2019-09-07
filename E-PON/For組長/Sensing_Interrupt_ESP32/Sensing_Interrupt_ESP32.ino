#include <TimerOne.h>
//#include <BluetoothSerial.h>
//BluetoothSerial SerialBT;//宣告藍芽物件=SerialBT

int potPin=36;//Up那一隻腳位
int sensorValue;

void setup(void)
{
  Timer1.initialize(2000);//2000表示2msec
  Timer1.attachInterrupt(readSensor); // blinkLED to run every 0.15 seconds
  Serial.begin(115200);
  //pinMode(potPin,ANALOG);
  //SerialBT.begin("BLETEST");//<<藍芽名稱，請自己記得  
}


void readSensor(void)
{
  sensorValue=analogRead(potPin);
  Serial.println(sensorValue,DEC);
  //SerialBT.print(sensorValue);
}


// The main program will print the blink count
// to the Arduino Serial Monitor
void loop(void)
{
//  noInterrupts();
//  interrupts();
  delay(100);
}
