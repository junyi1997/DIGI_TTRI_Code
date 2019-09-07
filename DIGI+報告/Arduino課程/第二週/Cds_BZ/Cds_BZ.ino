int potPin=A0;
int speakerPin=7;
void setup() {
  // put your setup code here, to run once:
  pinMode(potPin,INPUT);
  pinMode(speakerPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("ready");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(speakerPin,0);
  int val=analogRead(potPin);
  val=val*2;
  Serial.println(val);
  for(int i=0;i<50;i++){
    digitalWrite(speakerPin,1);
    delayMicroseconds(val);
    digitalWrite(speakerPin,0);
    delayMicroseconds(val);
    }
}
