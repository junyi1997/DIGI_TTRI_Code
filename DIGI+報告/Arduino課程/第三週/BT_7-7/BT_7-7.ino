int rx=15;//設定串列阜傳輸的輸入與輸出
int tx=14;
byte serialA;//宣告讀取手機命令的資料
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
  digitalWrite(PIN_0, LOW);
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

unsigned long time_previous;
void setup() {
  Serial.begin(9600);
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
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
  if(Serial.available()>0){
    serialA=Serial.read();
    Serial.println(serialA);
    }
  int a=serialA-48;
  // 不斷地寫入數字
  if (a==0){setDigit(0, 0); delay(5);}
  else {setDigit(0, a); delay(5);}
}
