int rx=15;//設定串列阜傳輸的輸入與輸出
int tx=14;
const int ledPin=13;//設定接腳13為接LED
byte serialA;//宣告讀取手機命令的資料
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);//設定鮑率
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    serialA=Serial.read();
    Serial.println(serialA);
    }
  switch(serialA){
    case '1':
    digitalWrite(ledPin,1);
    Serial.println("LED ON...");
    break;

    case '2':
    digitalWrite(ledPin,0);
    Serial.println("LED OFF...");
    break;

    default:
    break;
    }    
}
