char comdata; 
void setup(){
  Serial.begin(9600); //預設鲍率
  pinMode(2,OUTPUT); // LED接2腳位
}
void loop() {
  if(Serial.available()> 0){ //接收資料時
    comdata = Serial.read(); //存放資料
    if(comdata=='o'){ //如果為0
      while(Serial.available()==0); //等待資料
      comdata = Serial.read(); //存放資料
      if(comdata='n'){ //第二個字元如果為n
        digitalWrite(2,HIGH); //控制LED亮起
    }else if(comdata=='f'){//否則如果為f
      while(Serial.available()==0); //等待資料
        comdata = char(Serial.read()); //存放資料
        if(comdata=='f'){ //第三個字元如果為f
          digitalWrite(2,LOW);//控制LED熄滅
  }}}}}
