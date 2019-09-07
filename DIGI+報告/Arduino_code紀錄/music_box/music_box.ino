#include <SoftwareSerial.h> 
#include <Wire.h>  //引用二個函式庫SoftwareSerial及Wire SoftwareSerial 
SoftwareSerial I2CBT(2,3); //定義PIN2及PIN2分別為RX及TX腳位 


int ButtonPin=13;                     //定義按鈕接腳為第13腳位
int BZPin=3;                          //定義喇叭為第3腳位
int i=0;                              //定義陣列順序狀態
int BTStat=0;                         //儲存當下按鈕狀態
//輸入數字譜
//int Bee[]={0,7,11,12,13,12,11,7,11,6,7,11,1,2,3,4,3,2,3,11,
//           7,11,6,11,7,6,5,4,5,4,3,4,5,6,7,11,6,11,6,11,7,6,
//           7,11,12,11,7,11,6,7,11};
String Bee_S=" ";                     //儲存當下音階
int duration=300;                     //delay時間
//  低音         中音       高音
int Do0=262;int Do=523;int Do1=1047;
int Re0=294;int Re=587;int Re1=1175;
int Mi0=330;int Mi=659;int Mi1=1318;
int Fa0=349;int Fa=698;int Fa1=1397;
int So0=393;int So=784;int So1=1568;
int La0=440;int La=880;int La1=1760;
int Si0=494;int Si=988;int Si1=1976;
void setup() {
  pinMode(ButtonPin,INPUT_PULLUP);
  pinMode(BZPin,OUTPUT);
  Serial.begin(9600); //Arduino起始鮑率9600 
  I2CBT.begin(9600); //藍牙鮑率9600
  //(注意！此鮑率每個藍牙晶片不一定相同，請先確認完再填寫進去)
}
void loop() {
  byte cmmd[20];
  String Bee[100]={"13","12","11","07","06","05","06","07","13","12",
                   "11","07","06","05","06","07","15","13","14","15",
                   "13","14","15","05","06","07","11","12","13","14",
                   "13","11","12","13","03","04","05","06","05","04",
                   "05","03","04","05","04","06","05","04","03","02",
                   "03","02","01","02","03","04","05","06","04","06",
                   "05","06","07","11","05","06","07","11","12","13",
                   "14","15","03","03","04","05","03","04","15","05",
                   "06","07","11","12","13","14","03","16","17","11",
                   "03","04","03","04","03","02","03","11","07"};
  int ii=0;
  while(1){ 
    if (I2CBT.available()>0)
    {  //判斷有沒有訊息接收 
      for (int i=0; i<2; i++) {
        cmmd[i]=int(I2CBT.read()-48);//將接收的訊息顯示出來 
        Bee[ii]=String(cmmd[0])+String(cmmd[1]);
      }
      if(cmmd[0]==51){ii=0;break;}else{ii++;}
    }
  }
  int BTON=digitalRead(ButtonPin);
  //當按鈕壓下時
  //*************
  if(BTON==0){//*更改位置
  //*************  
    delay(10);
    if(BTStat==0){
      BTStat=1;
      if(i<100){i++;Bee_S=Bee[i];}
      else{i=0;}
      Serial.println(Bee[i]);
    }}else{
      BTStat=0;
      Bee_S=" ";
      //noTone(BZPin);
      }
  //音階輸出
  if(Bee_S=="01"){
      tone(BZPin,Do,duration);}
  else if(Bee_S=="02"){
      tone(BZPin,Re,duration);}
  else if(Bee_S=="03"){
      tone(BZPin,Mi,duration);}
  else if(Bee_S=="04"){
      tone(BZPin,Fa,duration);}
  else if(Bee_S=="05"){
      tone(BZPin,So,duration);}
  else if(Bee_S=="06"){
      tone(BZPin,La,duration);}
  else if(Bee_S=="07"){
      tone(BZPin,Si,duration);}
  else if(Bee_S=="11"){
      tone(BZPin,Do1,duration);}
  else if(Bee_S=="12"){
      tone(BZPin,Re1,duration);}
  else if(Bee_S=="13"){
      tone(BZPin,Mi1,duration);}
  else if(Bee_S=="14"){
      tone(BZPin,Fa1,duration);}
  else if(Bee_S=="15"){
      tone(BZPin,So1,duration);}
  else if(Bee_S=="16"){
      tone(BZPin,La1,duration);}
  else if(Bee_S=="17"){
      tone(BZPin,Si1,duration);}
  else if(Bee_S=="21"){
      tone(BZPin,Do0,duration);}
  else if(Bee_S=="22"){
      tone(BZPin,Re0,duration);}
  else if(Bee_S=="23"){
      tone(BZPin,Mi0,duration);}
  else if(Bee_S=="24"){
      tone(BZPin,Fa0,duration);}
  else if(Bee_S=="25"){
      tone(BZPin,So0,duration);}
  else if(Bee_S=="26"){
      tone(BZPin,La0,duration);}
  else if(Bee_S=="27"){
      tone(BZPin,Si0,duration);}
}
    
/*

  Melody on pin 8 of DUE

http://arduino.cc/en/Tutorial/Tone




// notes in the melody:
int melody[] = { 262,196, 196, 220, 196, 0,  247, 262 };
  //NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

void setup() {
}

void loop() {
  // iterate over the notes of the melody:

  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  delay(3000);

}



//Tone generator
//v1  use timer, and toggle any digital pin in ISR
//   funky duration from arduino version
//   TODO use FindMckDivisor?
//   timer selected will preclude using associated pins for PWM etc.
//    could also do timer/pwm hardware toggle where caller controls duration



// timers TC0 TC1 TC2   channels 0-2 ids 0-2  3-5  6-8     AB 0 1
// use TC1 channel 0 
#define TONE_TIMER TC1
#define TONE_CHNL 0
#define TONE_IRQ TC3_IRQn

// TIMER_CLOCK4   84MHz/128 with 16 bit counter give 10 Hz to 656KHz
//  piano 27Hz to 4KHz

static uint8_t pinEnabled[PINS_COUNT];
static uint8_t TCChanEnabled = 0;
static boolean pin_state = false ;
static Tc *chTC = TONE_TIMER;
static uint32_t chNo = TONE_CHNL;

volatile static int32_t toggle_count;
static uint32_t tone_pin;

// frequency (in hertz) and duration (in milliseconds).

void tone(uint32_t ulPin, uint32_t frequency, int32_t duration)
{
    const uint32_t rc = VARIANT_MCK / 256 / frequency; 
    tone_pin = ulPin;
    toggle_count = 0;  // strange  wipe out previous duration
    if (duration > 0 ) toggle_count = 2 * frequency * duration / 1000;
     else toggle_count = -1;

    if (!TCChanEnabled) {
      pmc_set_writeprotect(false);
      pmc_enable_periph_clk((uint32_t)TONE_IRQ);
      TC_Configure(chTC, chNo,
        TC_CMR_TCCLKS_TIMER_CLOCK4 |
        TC_CMR_WAVE |         // Waveform mode
        TC_CMR_WAVSEL_UP_RC ); // Counter running up and reset when equals to RC
  
      chTC->TC_CHANNEL[chNo].TC_IER=TC_IER_CPCS;  // RC compare interrupt
      chTC->TC_CHANNEL[chNo].TC_IDR=~TC_IER_CPCS;
       NVIC_EnableIRQ(TONE_IRQ);
                         TCChanEnabled = 1;
    }
    if (!pinEnabled[ulPin]) {
      pinMode(ulPin, OUTPUT);
      pinEnabled[ulPin] = 1;
    }
    TC_Stop(chTC, chNo);
                TC_SetRC(chTC, chNo, rc);    // set frequency
    TC_Start(chTC, chNo);
}

void noTone(uint32_t ulPin)
{
  TC_Stop(chTC, chNo);  // stop timer
  digitalWrite(ulPin,LOW);  // no signal on pin
}

// timer ISR  TC1 ch 0
void TC3_Handler ( void ) {
  TC_GetStatus(TC1, 0);
  if (toggle_count != 0){
    // toggle pin  TODO  better
    digitalWrite(tone_pin,pin_state= !pin_state);
    if (toggle_count > 0) toggle_count--;
  } else {
    noTone(tone_pin);
  }
}  
*/
