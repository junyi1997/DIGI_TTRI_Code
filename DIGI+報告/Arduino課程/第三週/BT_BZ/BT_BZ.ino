int rx=12;//設定串列阜傳輸的輸入與輸出
int tx=13;
int speakPin=7;//設定接腳13為接LED
byte serialA;//宣告讀取手機命令的資料
int duration=1000;
int Do=523;
int Re=587;
int Mi=659;
int Fa=698;
int So=784;
int La=880;
int Si=988;
int Do1=1047;
void setup() {
  // put your setup code here, to run once:
  pinMode(speakPin,OUTPUT);
  Serial.begin(9600);//設定鮑率
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    serialA=Serial.read();
    Serial.println(serialA);
    }
  switch(serialA){
    case '1':
    serialA=0;
    tone(speakPin,Do,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("Do...");
    break;

    case '2':
    serialA=0;
    tone(speakPin,Re,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("Re...");
    break;

    case '3':
    serialA=0;
    tone(speakPin,Mi,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("Mi...");
    break;

    case '4':
    serialA=0;
    tone(speakPin,Fa,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("Fa...");
    break;

    case '5':
    serialA=0;
    tone(speakPin,So,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("So...");
    break;

    case '6':
    serialA=0;
    tone(speakPin,La,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("LA...");
    break;

    case '7':
    serialA=0;
    tone(speakPin,Si,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("Si...");
    break;

    case '8':
    serialA=0;
    tone(speakPin,Do1,duration);
    delay(duration);
    noTone(speakPin);
    Serial.println("Do1...");
    break;

    default:
    break;
    }    
}
