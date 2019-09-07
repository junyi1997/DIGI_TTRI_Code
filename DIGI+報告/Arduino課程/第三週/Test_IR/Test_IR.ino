int irLed=2;                                        //設定irLed由第2腳位控制
int irSensor=4;                                     //設定irSensor由第4腳位控制
unsigned int frequence=38000;                       //給紅外線發射器的頻率
void setup() {
  // put your setup code here, to run once:
  pinMode(irSensor,INPUT);                          //設定4腳位為輸出
  pinMode(irLed,OUTPUT);                            //設定2腳位為輸入
  Serial.begin(9600);                               //設定鮑率
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor;                                       //建立一變數儲存紅外線狀態
  //-------------------------------偵測紅外線的狀態
  tone(irLed,frequence);                            //紅外線開始發射
  delay(10);                                        //延遲10ms
  sensor=digitalRead(irSensor);                     //讀取紅外線感測器狀態
  noTone(irLed);                                    //紅外線停止發射
  Serial.print("irSensor:");        
  Serial.print(sensor);
  Serial.println("___");
}
