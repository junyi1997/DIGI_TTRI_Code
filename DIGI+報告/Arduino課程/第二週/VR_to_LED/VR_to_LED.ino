int potPin=A3;
int ledPin=9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(potPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int SensorValue=analogRead(potPin);   //將可變電阻的值紀錄在變數SensorValue
  Serial.println(SensorValue,DEC);      //把變數SensorValue打印
  SensorValue=SensorValue/4;            //把SensorValue的值從0~1024降至0~255
  analogWrite(ledPin,SensorValue);      //將轉換後的值傳來控制LED亮滅程度
  delay(150);                           //延遲150ms
}
