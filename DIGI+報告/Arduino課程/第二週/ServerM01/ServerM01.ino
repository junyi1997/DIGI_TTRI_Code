//不能用
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int servoPin=9;
void setup() {
  pinMode(servoPin,OUTPUT);
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  myservo.write(0); 
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<=40;i++){
    digitalWrite(servoPin,1);
    delayMicroseconds(1000);
    digitalWrite(servoPin,0);
    delayMicroseconds(20);
    }  
   delay(100);
  for(int i=0;i<=40;i++){
    digitalWrite(servoPin,1);
    delayMicroseconds(2000);
    digitalWrite(servoPin,0);
    delayMicroseconds(20);
    }
  
  
}
