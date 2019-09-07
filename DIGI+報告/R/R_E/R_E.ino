int v=0;
float volt=0.0;
float R=0.0;
int R_2=0;
float R1=1000.0;
int i = 0;
void setup() 
{ 
  Serial.begin(9600); //指定串口通訊比特率為9600 
} 
void loop() 
{ 
  v = analogRead(A0); //從A0口讀取電壓，模擬埠電壓測量範圍為0-3.3V，返回的值為0-1024 
  volt = v * (3.3 / 1023.0); //將返回值換算成電壓 
  if(volt<0.02){delay(1);}//Serial.println("Max_Error")
  else if(volt>3.2){delay(1);}//Serial.println("Min_Error")  
  else
    {
      Serial.print("V："); 
      Serial.print(volt);
      Serial.println("V"); 
      R = abs((5.0*R1/volt)-R1);//透過分壓定理將R值算出來
      i=0;
      while((R/10.0)>1.0)
      {
        R=R/10;
        i++;
      }
      R_2=int(R*100);
      R_2=R_2*10+i;
      Serial.print("R："); 
      Serial.print(R_2);
      Serial.println("Ω"); 
      Serial.println(i);
      delay(1000);
    }
}
