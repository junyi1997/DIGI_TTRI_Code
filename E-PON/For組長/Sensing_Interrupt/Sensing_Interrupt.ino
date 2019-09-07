#include <TimerOne.h>
#include <SoftwareSerial.h> 
#include <Wire.h>  //引用二個函式庫SoftwareSerial及Wire SoftwareSerial 
SoftwareSerial BT(2,3); //定義PIN2及PIN2分別為RX及TX腳位 

int potPin=A0;
int sensorValue;

void setup(void)
{
  Timer1.initialize(2000);//2000表示2msec
  Timer1.attachInterrupt(readSensor); // blinkLED to run every 0.15 seconds
  Serial.begin(115200);
  pinMode(potPin,INPUT);
  BT.begin(9600);  
}


void readSensor(void)
{
  sensorValue=analogRead(potPin);
  Serial.println(sensorValue,DEC);
  BT.print(sensorValue);
}


// The main program will print the blink count
// to the Arduino Serial Monitor
void loop(void)
{
//  noInterrupts();
//  interrupts();
  delay(100);
}
