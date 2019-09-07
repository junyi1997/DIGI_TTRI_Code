//由串列阜送出資料
int rx=15;//設定串列阜傳輸的輸入與輸出
int tx=14;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//設定鮑率
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("HEllo this is Arduino ^_^");
}
