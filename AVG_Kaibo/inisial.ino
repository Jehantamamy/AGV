void inisialLCD(){
  lcd.backlight();    //LCD
  lcd.init();         //LCD
}

void inisialGaris(){
  /* Set-up IR sensor pins as input */
  for (int i = 0; i <= 7; i++) 
  {pinMode(irPins[i], INPUT);}

  for (int i = 0; i <= 7; i++) 
  {pinMode(irInd[i], OUTPUT);}
}
void inisialMotor(){
  pinMode(pwmrem1, OUTPUT);
  pinMode(pwmrem2, OUTPUT);
  digitalWrite(pwmrem1,0);
  digitalWrite(pwmrem2,0);
}
void inisialSound(){
  Serial2.begin(9600);
  if (!myDFPlayer.begin(Serial2)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    lcd.setCursor(0,0);
    lcd.print("  SOUND ERROR   ");
    delay(500);
    //while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  lcd.setCursor(0,0);
  lcd.print("  SOUND OK      ");
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
}

void inisialTimer1(){
  cli();//stop interrupts

  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  //OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  OCR1A = 1000;
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();
}

void disableTImer1(){
  cli();
  TIMSK1 |= (0 << OCIE1A);
  sei();
}
