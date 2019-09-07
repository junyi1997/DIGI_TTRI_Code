int v =0;
// 定義腳位
#define PIN_a 2
#define PIN_b 3
#define PIN_c 4
#define PIN_d 5
#define PIN_e 6
#define PIN_f 7
#define PIN_g 8
#define PIN_h 9
#define PIN_0 10
// 共有4個七段顯示器，分別由針腳PIN_0、PIN_1、PIN_2、PIN_3控制
// 七段顯示器裡有8個LED（包含小數點）
#define SEG_NUM 8
const byte seg_pins[SEG_NUM] = {PIN_a, PIN_b,
PIN_c, PIN_d,PIN_e, PIN_f, PIN_g, PIN_h};
// 底下定義由七段顯示器顯示數字時所需要的資料
const boolean data[10][SEG_NUM] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};
// 設定某個七段顯示器所顯示的數字，
// 參數n為0~9，顯示數字
void setDigit(int pos, int n){
  // 控制想要更新哪一個七段顯示器，將其腳位設為LOW
  // 其他腳位則設為HIGH，代表不更新。 
  for(int p = 0; p < 1; p++){
    if(p == pos)
      digitalWrite(PIN_0, LOW);
    else
      digitalWrite(PIN_0, HIGH);
  }
  // 寫入數字 
  if(0 <= n && n <= 9){
    for(int i = 0; i < SEG_NUM; i++){
      digitalWrite(seg_pins[i], data[n][i] == 1 ? HIGH : LOW);
    }
  }
  else{
    for(int i = 0; i < SEG_NUM; i++){
      digitalWrite(seg_pins[i], LOW);
    }
    digitalWrite(PIN_h, HIGH);
  }
}
// 設定整個七段顯示器想要顯示的數字
// 參數number的範圍應是0~9
void setNumber(int number)
{
  int n0 = number % 10;
  // 求出個位數的值後，進行更新
  // 注意，此處以delay(5)隔開位數的更新 
  setDigit(0, n0); delay(5);
}
unsigned long time_previous;
void setup() {
  Serial.begin(9600);
  pinMode(PIN_0, OUTPUT);
  digitalWrite(PIN_0, HIGH);
  for(int i = 0; i < SEG_NUM; i++){
    pinMode(seg_pins[i], OUTPUT);
    digitalWrite(seg_pins[i], LOW);
  }
  time_previous = millis();
}
int number = 0;
void loop() {   
  // 經過一秒後就讓number加1 
  unsigned long time_now = millis();
  if(time_now - time_previous > 1000){
    //從A0口讀取電壓，模擬埠電壓測量範圍為0-3.3V，返回的值為0-1024 
    v = analogRead(A0); 
    Serial.println(v);
    v=v/100;
    number=v;
    time_previous += 1000;
  }
  // 不斷地寫入數字
  if (v==0){setNumber(0);}
  else if (v==10){setNumber(0);}
  else {setNumber(number);}
}
