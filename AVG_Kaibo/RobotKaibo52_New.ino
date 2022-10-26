#include <stdio.h>
#include <Keypad.h>
#include "kalibrasi.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//#include <Gwiot7941e.h>

//rfid
//#define GWIOT_7941E_RX_PIN 52
//#define READ_LED_PIN 13
//Gwiot7941e gwiot7941e;
//String dataRFID;


//int LineStop[5]={1,2,3,4,5}, menu1=0,nilai,ErrRot;

//KEYPAD

const byte ROWS = 5;
const byte COLS = 4;
int SimpanData=0;
char keymap [ROWS][COLS]=
{
  {'A','B','#','*'},
  {'1','2','3','U'},
  {'4','5','6','D'},
  {'7','8','9','C'},
  {'L','0','R','E'},
};
byte rowPins[ROWS] = {51,49,47,45,43};
byte colPins[COLS] = {24,26,28,30};
Keypad customKeypad = Keypad( makeKeymap(keymap), rowPins, colPins, ROWS, COLS); 
char dataSer[100];

//LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//MOTOR
const int pwm1 = 9;           
const int pwm2 = 8;  
const int pwm3 = 4; 
int TimerJalan = 0;

const int pwm4 = 5; 
const int pwmser1 = 7;
const int pwmser2 = 6;
const int Lim = 22; 
const int pwmrem1 = 23;           
const int pwmrem2 = 25;  
#define KANAN 0
#define KIRI  1 

//LINE
int Error, D_Err ,Last_Err, Sterring, Flag, MKA, MKI;
int Rot;
int Smooth=0;
int Keluar=0;
int PWM=0,kondisi3;
const int irPins[8] = {A6, A7, A4, A5, A2, A3, A0, A1};
const int irInd[8] = {41, 39, 37, 35, 33, 31, 29, 27};
int irSensorDigital[8] = {0,0,0,0,0,0,0,0};
int irSensorAnalog[8];
int dataRot;

//SOUND
/* Define motor contr oll inputs */
#include "Arduino.h"
#include <stdio.h>
#include "DFRobotDFPlayerMini.h"
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

//US
const int Sensor1 = 32;//46;
const int Sensor2 = 34;//42;
const int Sensor3 = 36;//36;
const int Sensor4 = 38;//34; 
byte distance2;
byte distance3;
byte distance4;
byte distance5;
int TimerMusic=0;

//Timer 1
ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  linetracking(KecepatanMotor,255);
}

//RFID
#define RS485Transmit    HIGH
#define RS485Receive     LOW
#define SSerialTxControl 53
byte byteSend[9];
char dataCard[3];
int flag=0;
char dataRFID[30];

void setup() {
  
  // put your setup code here, to run once:
  inisialMotor();
  Serial.begin(57600);
  Serial1.begin(9600);
  Serial3.begin(9600);
  TimerJalan = 0;
  inisialLCD();
  inisialGaris();
  
  inisialSound();
  pinMode(Lim,INPUT_PULLUP);
  pinMode(Sensor1,INPUT); //UNO
  pinMode(Sensor2,INPUT); //UNO
  pinMode(Sensor3,INPUT); //UNO
  pinMode(Sensor4,INPUT); //UNO
  berhenti();
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), rotary, RISING);
  AngkatMotor();
  LEDKelip(5);
  KecepatanMotor = 0;
  inisialTimer1();
  //gwiot7941e.begin(GWIOT_7941E_RX_PIN);
  lcd.setCursor(0,0);
  lcd.print("      KAIBO     ");
  delay(500);
  kondisi1 = 0;
  kondisi2 = 0;
  //myDFPlayer.playMp3Folder(1);
  char customKey = customKeypad.getKey();
  while(customKey != '*'){
    lcd.setCursor(0,0);
    lcd.print("     TEKAN *    ");
    customKey = customKeypad.getKey();
    scanD();
  }
  lcd.clear();
  TurunMotor();
  LEDKelip(3);
//  programUtama("XX XX XX XX");
//  StopinLine();
  //programUtama(HOME);
  //StopinLine();
}

void loop() {
  cekSerial3();
  // put your main code here, to run repeatedly:
  //cekKeypad();
  //cekMotor();
  //  cekSensor();
  //cekUS();
  //cekRotary();
  //cekRFID();
  //cekMotorRem();
  //cekUS();
  /*if(kondisi3 == 0){
     myDFPlayer.playMp3Folder(2);
     //myDFPlayer.playMp3Folder(1);
     PWM = 0;
  }
  kondisi1 = 0;
  kondisi2 = 0;
  kondisi3 = 1;
  berhenti();*/
  //menu();
  //scanD();
  //cekLED();
}

void rotary(){
  if(digitalRead(3) == HIGH){
    Rot++;
  }
  else{
    Rot--;
  }
}
