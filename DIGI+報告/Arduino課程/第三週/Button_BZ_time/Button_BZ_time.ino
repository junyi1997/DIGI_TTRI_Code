int inPin=10;                                       //按鈕接10腳位
int sperkerPin=9;                                   //蜂鳴器接9腳位
int base=500;                                       //基本音頻
unsigned long duration;                             //無符號長整數 
void setup() {
  // put your setup code here, to run once:
  pinMode(inPin,INPUT);                             //設定10腳位為輸出
  pinMode(sperkerPin,OUTPUT);                       //設定9腳位為輸入
  Serial.begin(9600);                               //設定鮑率
}
//按鈕第一下為開始讀取按壓的時間，第二下為結束讀取按壓的時間
void loop() {
  // put your main code here, to run repeatedly:
  duration=pulseIn(inPin,HIGH,0.3);                 //讀取按壓的時間
  if(duration>0){                                   //讀取值不為零
    Serial.print("HIGH_duration:");
    Serial.println(duration);
    int voice=duration/10000+base;                  //10ms為1單位+基本音頻
    Serial.print("voice:");
    Serial.println(voice);
    tone(sperkerPin,voice,500);                     //輸出音頻0.5秒
    delay(500);                                     //延遲0.5秒
    } 
}
