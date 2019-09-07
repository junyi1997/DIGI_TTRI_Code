int ledPin=13;
int inPin=10;
int val=0;
int speakerPin=9;
int length = 15;
char notes[]="ccggaagffeeddc ";
int beats[]={1,1,1,1,1,1,2,1,1,1,1,1,1,2,4};
int tempo=300;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(speakerPin,OUTPUT);
  pinMode(inPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(inPin);
  Serial.println(val);
  delay(100);
  if (val==1){
    digitalWrite(ledPin,0);
  }else{
    digitalWrite(ledPin,1);
    for(int i=0;i<length;i++){
      if(notes[i]==' '){
        delay(beats[i]*tempo);//rest
      }else{
        playNote(notes[i],beats[i] * tempo);
      }
      delay(tempo/2);
      }
    } 
}
void playTone(int tone,int duration){
  for(long i = 0;i<duration*1000L;i+=tone*2){
    digitalWrite(speakerPin,1);
    delayMicroseconds(tone);
    digitalWrite(speakerPin,0);
    delayMicroseconds(tone);
    }
  }
void playNote(char note,int duration){
  char names[]={'c','d','e','f','g','a','b','C'};
  int tones[]={1915,1700,1519,1432,1275,1136,1014,956};
  for(int i = 0 ; i < 8 ; i++){
    if(names[i]==note){
      playTone(tones[i],duration);
      }
    }
  }
  
