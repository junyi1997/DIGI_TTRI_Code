int delayValue=100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=digitalRead(2);
  if(val==1){
    //digitalWrite(LED_BUILTIN, HIGH);
    delayValue=1000;
  }else{
    //digitalWrite(LED_BUILTIN, 0);
    delayValue=100;
  }
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delayValue);
  digitalWrite(LED_BUILTIN, 0);
  delay(delayValue);
  
}
