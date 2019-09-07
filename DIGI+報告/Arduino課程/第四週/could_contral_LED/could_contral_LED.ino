unsigned long MS_TIMER=0;
unsigned long lastMSTimer=0;
String comdata="";
char flag=false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  MS_TIMER=millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(flag==false){
    if(millis()-MS_TIMER>5000){
      Serial.println("comd=subscribe&topic=playrobot");
      MS_TIMER=millis();  
    }  
  }
  if(Serial.available()>0){
    comdata+=char(Serial.read());
    lastMSTimer=millis();
    delay(5);  
  }
  if(comdata.length()>0&&millis-lastMSTimer>100){
    if(comdata.compareTo("cmd=subscribe&res=1\r\n")==0){
      flag=true;    
    }else if(comdata.compareTo("cmd=publish&device_name=arduino&device_cmd=d2on\r\n")==0){
       digitalWrite(2,1);
    }else if(comdata.compareTo("cmd=publish&device_name=arduino&device_cmd=d2off\r\n")==0){
       digitalWrite(2,0);
       comdata="";
    }
  }
}
