#include <SoftwareSerial.h> 
#include <Wire.h>  //引用二個函式庫SoftwareSerial及Wire SoftwareSerial 
SoftwareSerial I2CBT(2,3); //定義PIN2及PIN2分別為RX及TX腳位 


void setup() { 
  Serial.begin(9600); //Arduino起始鮑率9600 
  I2CBT.begin(9600); //藍牙鮑率9600
  //(注意！此鮑率每個藍牙晶片不一定相同，請先確認完再填寫進去) 
} 

void loop() { 
  byte cmmd[20];
  String Bee[100];
  int ii=0;
  while(1){ 
  if (I2CBT.available()>0)
  {  //判斷有沒有訊息接收 
    for (int i=0; i<2; i++) {
      cmmd[i]=int(I2CBT.read()-48);//將接收的訊息顯示出來 
      Bee[ii]=String(cmmd[0])+String(cmmd[1]);
    }
    if(cmmd[0]==51){break;}
    //Serial.println(Bee[ii]);
    ii++;
  }
  }
  for(int iii = 0 ; iii < ii;iii++){
    if(Bee[iii]=="01"){Serial.println("Do");}
    else if(Bee[iii]=="02"){Serial.println("Re");}
    else if(Bee[iii]=="03"){Serial.println("Me");}
    else if(Bee[iii]=="04"){Serial.println("Fa");}
    else if(Bee[iii]=="05"){Serial.println("So");}
    else if(Bee[iii]=="06"){Serial.println("La");}
    else if(Bee[iii]=="07"){Serial.println("Si");}
    else if(Bee[iii]=="11"){Serial.println("Do1");}
    else if(Bee[iii]=="12"){Serial.println("Re1");}
    else if(Bee[iii]=="13"){Serial.println("Me1");}
    else if(Bee[iii]=="14"){Serial.println("Fa1");}
    else if(Bee[iii]=="15"){Serial.println("So1");}
    else if(Bee[iii]=="16"){Serial.println("La1");}
    else if(Bee[iii]=="17"){Serial.println("Si1");}
    else if(Bee[iii]=="21"){Serial.println("Do0");}
    else if(Bee[iii]=="22"){Serial.println("Re0");}
    else if(Bee[iii]=="23"){Serial.println("Me0");}
    else if(Bee[iii]=="24"){Serial.println("Fa0");}
    else if(Bee[iii]=="25"){Serial.println("So0");}
    else if(Bee[iii]=="26"){Serial.println("La0");}
    else if(Bee[iii]=="27"){Serial.println("Si0");}
    
    //Serial.println(Bee[0]);
    } 
    Serial.print("總共為");
    Serial.print(ii);
    Serial.println("個音符");
    Serial.println("END");
    ii=0;
    
  
}
