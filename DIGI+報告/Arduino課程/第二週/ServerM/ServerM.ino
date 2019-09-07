int servoPin=9;
void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(servoPin,1);
  delayMicroseconds(1500);
  digitalWrite(servoPin,0);
  delayMicroseconds(1500);
}
