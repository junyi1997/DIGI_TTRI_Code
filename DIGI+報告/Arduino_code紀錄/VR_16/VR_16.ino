int vPin[]={A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11};
float v[]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
float volt[]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
float R[]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
float R1=100000.0;
int k=0;
void setup() 
{ 
  Serial.begin(115200); //指定串口通訊比特率為9600 
  //Serial.print(sizeof(vPin)/4);
  
} 
void loop() 
{ 
  Serial.println("|編號  |電壓    |阻值"); 
  for(int i = 0 ; i < sizeof(vPin)/4 ;i++){
    v[i] = analogRead(vPin[i]); //從A0口讀取電壓，模擬埠電壓測量範圍為0-3.3V，返回的值為0-1024 
    volt[i] = v[i] * (3.3 / 1023.0); //將返回值換算成電壓 
    R[i] = abs((4.88*R1/volt[i])-R1);//透過分壓定理將R值算出來
    
    Serial.print("|");
    Serial.print(i+1);   
    if(i<=8){
      Serial.print("    |");
    }else{
      Serial.print("   |");
    }
    Serial.print(volt[i]);
    Serial.print("V   |");  
    Serial.print(R[i]);
    Serial.println("Ω|"); 
  }
  Serial.println(""); 
  delay(120);  
}
