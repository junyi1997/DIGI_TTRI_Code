int threshold = 40;
bool touch1detected = false;
bool touch2detected = false;
bool touch3detected = false;
bool touch4detected = false;
bool touch5detected = false;
bool touch6detected = false;
bool touch7detected = false;
bool touch8detected = false;
int state[]={0,0,0,0,0,0,0,0};

void gotTouch1(){
 touch1detected = true;
}
void gotTouch2(){
 touch2detected = true;
}
void gotTouch3(){
 touch3detected = true;
}
void gotTouch4(){
 touch4detected = true;
}
void gotTouch5(){
 touch5detected = true;
}
void gotTouch6(){
 touch6detected = true;
}
void gotTouch7(){
 touch7detected = true;
}
void gotTouch8(){
 touch8detected = true;
}

void setup() {
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  printf("\n ESP32 Touch Interrupt Test\n");
  touchAttachInterrupt(T0, gotTouch1, threshold);
  touchAttachInterrupt(T4, gotTouch2, threshold);
  touchAttachInterrupt(T5, gotTouch3, threshold);
  touchAttachInterrupt(T6, gotTouch4, threshold);
  touchAttachInterrupt(T7, gotTouch5, threshold);
  touchAttachInterrupt(T9, gotTouch6, threshold);
  touchAttachInterrupt(T8, gotTouch7, threshold);
  touchAttachInterrupt(T3, gotTouch8, threshold);
  
}

void loop(){
  if(touch1detected){
    touch1detected = false;
    Serial.println("Touch 1 detected");
  }
  if(touch2detected){
    touch2detected = false;
    Serial.println("Touch 2 detected");
  }
  if(touch3detected){
    touch3detected = false;
    Serial.println("Touch 3 detected");
  }
  if(touch4detected){
    touch4detected = false;
    Serial.println("Touch 4 detected");
  }
  if(touch5detected){
    touch5detected = false;
    Serial.println("Touch 5 detected");
  }
  if(touch6detected){
    touch6detected = false;
    Serial.println("Touch 6 detected");
  }
  if(touch7detected){
    touch7detected = false;
    Serial.println("Touch 7 detected");
  }
  if(touch8detected){
    touch8detected = false;
    Serial.println("Touch 8 detected");
  }
  
}
