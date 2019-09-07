int LEDpin1=2;                  //定義第一顆LED接腳
int LEDpin2=3;                  //定義第二顆LED接腳
int LEDpin3=4;                  //定義第三顆LED接腳
int Butpin=5;                   //定義按鈕接腳

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           //設定褒率(傳輸速率)
  pinMode(LEDpin1,OUTPUT);      //定義第一顆LED接腳為輸出控制
  pinMode(LEDpin2,OUTPUT);      //定義第二顆LED接腳為輸出控制
  pinMode(LEDpin3,OUTPUT);      //定義第三顆LED接腳為輸出控制
  pinMode(Butpin,INPUT);        //定義按鈕接腳為輸入控制
}

void loop() {
  // put your main code here, to run repeatedly:
  butLED();                    //進入由開關控制LED燈的程式
  blink1();                    //進入閃爍LED燈的程式
  con();                       //進入對話框控制LED燈的程式
}
void butLED(){                 //定義由開關控制LED燈的程式
  int val=digitalRead(Butpin); //設定一val變數得知按鈕狀況為高還低準位
  if(val==1){                  //如果按鈕狀況為高準位時
    digitalWrite(LEDpin3, HIGH);//讓第三顆LED燈亮
  }else{                       //如果按鈕狀況為低準位時
    digitalWrite(LEDpin3, 0);  //讓第三顆LED燈熄滅
  }
}
void blink1(){                 //進入閃爍LED燈的程式
  digitalWrite(LEDpin1, 1);    //讓第一顆LED燈亮
  delay(100);                  //延遲1秒
  digitalWrite(LEDpin1, 0);    //讓第一顆LED燈熄滅
  delay(100);                  //延遲1秒
  }

void con(){                    //進入對話框控制LED燈的程式
    if(Serial.available()){    //如果對話框有文字輸入時
    char ch = Serial.read();   //定義ch變數儲存對話框內輸入文字
    Serial.print(ch);          //將對話框的輸入文字顯示出來
    switch(ch){                //將對話框的輸入文字進行判斷
      case '0':                //如果對話框的輸入文字為'0'時
        digitalWrite(LEDpin2,1);//讓第二顆LED燈亮
        delay(1000);            //延遲1秒
        break;                  //強制離開迴圈
      case '1':                 //如果對話框的輸入文字為'1'時
        digitalWrite(LEDpin2,0); //讓第二顆LED燈熄滅
        break;                  //強制離開迴圈 
      }
    }
  }  
