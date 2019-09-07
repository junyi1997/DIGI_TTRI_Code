void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Ready");
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char ch = Serial.read();
    Serial.print(ch);
    switch(ch){
      case '0':
        digitalWrite(13,1);
        delay(1000);
        break;
      case '1':
        digitalWrite(13,0); 
        break; 
      }
    
    }
}
