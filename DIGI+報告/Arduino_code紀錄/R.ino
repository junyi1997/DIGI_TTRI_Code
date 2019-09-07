int v=0;
int v1=0;
float volt=0;
float R=0;
float R1=1000.0;
void setup() { 
  Serial.begin(9600); //指定串口通訊比特率為9600 
  } 
void loop() { 
  v = analogRead(A0); //從A0口讀取電壓，模擬埠電壓測量範圍為0-3.3V，返回的值為0-1024 
  Serial.print("A0="); 
  v1=v-200;
  Serial.println(v);
  volt = v * (3.3 / 1024.0); //將返回值換算成電壓 
  Serial.print("V="); 
  Serial.print(volt);
  Serial.println("v");
  
  R = abs((5.0*R1/volt)-R1)/10;
  if(R<1000000.0){
  Serial.print("R=");  
  Serial.print(R); 
  Serial.println("Ω"); 
  delay(1000);
  }else if(R<100.0){
  delay(1);
  }else{
  delay(1);
  }
}
