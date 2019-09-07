int inPin=10;                                       //按鈕接10腳位
unsigned long duration;                             //無符號長整數
void setup() {
  // put your setup code here, to run once:
  pinMode(inPin,INPUT);                             //設定10腳位為輸出
  Serial.begin(9600);                               //設定鮑率
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(inPin)==0){}                    //按鈕為按下無限迴圈
  duration=pulseIn(inPin,LOW);                      //讀取間隔的時間
  if(duration>1000){                                //避免雜訊
    Serial.print("Time=");                          //螢幕顯示
    Serial.print(duration);                         //時間
    Serial.println("us");                           //單位
    delay(500);                                     //延遲0.5秒
  }
  
}
