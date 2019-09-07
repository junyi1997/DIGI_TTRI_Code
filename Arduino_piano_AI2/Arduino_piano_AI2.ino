#include <SoftwareSerial.h>
#include <Wire.h>
int BT_Do_Pin=2;
int BT_Re_Pin=3;
int BT_Mi_Pin=4;
int BT_Fa_Pin=5;
int BT_So_Pin=6;
int BT_La_Pin=7;
int BT_Si_Pin=8;

SoftwareSerial BT(10,11); 
  
void setup() {
  BT.begin(9600);   
  Serial.begin(9600);
  pinMode(BT_Do_Pin,INPUT);
  pinMode(BT_Re_Pin,INPUT);
  pinMode(BT_Mi_Pin,INPUT);
  pinMode(BT_Fa_Pin,INPUT);
  pinMode(BT_So_Pin,INPUT);
  pinMode(BT_La_Pin,INPUT);
  pinMode(BT_Si_Pin,INPUT); 
}
  
void loop() {
  while(true){
    if(digitalRead(BT_Do_Pin)==1){
        BT.print(1);
        Serial.println("Do");
        delay(500);
    }else if(digitalRead(BT_Re_Pin)==1){
        BT.print(2);
        Serial.println("Re");
        delay(500);
    }else if(digitalRead(BT_Mi_Pin)==1){
        BT.print(3);
        Serial.println("Mi");
        delay(500);
    }else if(digitalRead(BT_Fa_Pin)==1){
        BT.print(4);
        Serial.println("Fa");
        delay(500);
    }else if(digitalRead(BT_So_Pin)==1){
        BT.print(5);
        Serial.println("So");
        delay(500);
    }else if(digitalRead(BT_La_Pin)==1){
        BT.print(6);
        Serial.println("La");
        delay(500);
    }else if(digitalRead(BT_Si_Pin)==1){
        BT.print(7);
        Serial.println("Si");
        delay(500);
    }else{;}    
  } 
}
