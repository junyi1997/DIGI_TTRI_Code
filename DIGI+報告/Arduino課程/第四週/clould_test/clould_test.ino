String User_name="arduino";//輸入Devices Control中的Device name
String UID="IFTTT";//輸入Get API key 中的 Uid
String key="548f9f399c84f20e59439c873967367f";//輸入金鑰
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.print("cmd=upload&device_name=");
  Serial.print(User_name);
  Serial.print("&data=");
  Serial.print(random(1000));
  Serial.print("&uid=");
  Serial.print(UID);
  Serial.print("&key=");
  Serial.println(key);
}  
  /*
  Serial.print("cmd=upload&device_name=arduino&data=");
  Serial.print(random(1000));
  Serial.println("&uid=IFTTT&key=548f9f399c84f20e59439c873967367f");
  */
