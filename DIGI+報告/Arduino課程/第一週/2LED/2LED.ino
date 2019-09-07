int ledpin1=4;
int ledpin2=5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Ready");
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char ch = Serial.read();
    //Serial.print(ch);
    switch(ch){
      case '0':
        digitalWrite(ledpin1,1);
        digitalWrite(ledpin2,0);
        delay(1000);
        break;
      case '1':
        digitalWrite(ledpin1,0);
        digitalWrite(ledpin2,1); 
        break; 
      }
    
    }
}
