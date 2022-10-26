void linetracking(unsigned char Speed, unsigned char Max) 
{
  dataRot = Rot;
  //ErrRot = Speed - dataRot; 
  //PWM = PWM + (ErrRot/10);
  //if(PWM >255) PWM =255;
  //else if(PWM <20) PWM =20;
  if(dataRot > Speed) {PWM=PWM-5 ; if(PWM <120) PWM =120;}
  else{PWM=PWM+1; if(PWM >255) PWM =255;}
  //Serial.println(dataRot);
  // 0= putih 1= hitam
  if(irSensorDigital[3] == 1 && irSensorDigital[4] == 1 && irSensorDigital[0] == 1)     {Error =  -1;  Flag=0;}
  else if(irSensorDigital[3] == 1 && irSensorDigital[4] == 1 && irSensorDigital[7] == 1){Error =  1;  Flag=1;}
  else if(irSensorDigital[3] == 1 && irSensorDigital[4] == 1){Error =  0;  }
  else if(irSensorDigital[2] == 1 && irSensorDigital[3] == 1){Error =  -1;  Flag=0;}
  else if(irSensorDigital[4] == 1 && irSensorDigital[5] == 1){Error =  1;  Flag=1;}
  else if(irSensorDigital[3] == 1 )                          {Error =  0;  Flag=0;}
  else if(irSensorDigital[4] == 1 )                          {Error =  0;  Flag=1;}
  else if(irSensorDigital[1] == 1 && irSensorDigital[2] == 1){Error =  -2;  Flag=0;}
  else if(irSensorDigital[5] == 1 && irSensorDigital[6] == 1){Error =  2;  Flag=1;}
  else if(irSensorDigital[2] == 1 )                          {Error =  -1;  Flag=0;}
  else if(irSensorDigital[5] == 1 )                          {Error =  1;  Flag=1;}
  else if(irSensorDigital[0] == 1 && irSensorDigital[1] == 1){Error =  -3;  Flag=0;}
  else if(irSensorDigital[6] == 1 && irSensorDigital[7] == 1){Error =  3;  Flag=1;}
  else if(irSensorDigital[1] == 1 )                          {Error =  -2;  Flag=0;}
  else if(irSensorDigital[6] == 1 )                          {Error =  2;  Flag=1;}
  
  //else if(irSensorDigital[0] == 1 )                          {Error =  -3;  Flag=0;}
  
  //else if(irSensorDigital[7] == 1 )                          {Error =  3;  Flag=1;}
  else if(irSensorDigital[0] == 1){Error =  -4;  Flag=0;}
  else if(irSensorDigital[7] == 1){Error =  4;  Flag=1;}
  else {
      if(Flag == 0){
        Error = -10;
      }
      else{
        Error = 10;
      }
  }
  if(Error < 5 && Error > -5){
    D_Err=Error-Last_Err;
    if(PWM>150) {Kp= 13; Kd=23; }
    else {Kp=13; Kd=23;}
    Sterring = Kp*Error+Kd*D_Err;
    Last_Err=Error;
    MKI = PWM + Sterring;
    MKA = PWM - Sterring;
    if(MKA > 255) MKA = 255;
    else if(MKA > PWM) MKA = PWM;
    else if(MKA<0) MKA = 0;
    if(MKI > 255) MKI = 255;
    else if(MKI > PWM) MKI = PWM;
    else if(MKI<0) MKI = 0; 
    if(Speed == 0) berhenti();
    else maju(MKI,MKA); // matikan motor
    Rot=0;
    Keluar=0;
    //lcd.setCursor(0,0);
    //lcd.print(PWM);
    //delay(10);
  }
  else{ // keluar jalur
    Keluar++;
    //lcd.setCursor(0,14);
    //lcd.print(Keluar);
    if(Keluar>=DelayKeluar){
      berhenti();
      if(TimerJalan == 1){
        delay(2000);
        disableTImer1();
        myDFPlayer.stop();
        /*delay(1000);
        char customKey = 0;
        while(customKey != '*'){
          lcd.setCursor(0,0);
          lcd.print("     TEKAN *    ");
          customKey = customKeypad.getKey();
         // scanD();
        }*/
        StopinLine();
        while(1){
          berhenti();
          //AngkatMotor();
          lcd.setCursor(0,0);
          lcd.print("ROBOT KELUAR    ");
          LEDKelip(5);
          KecepatanMotor = 0;
        }
      }
    }
  }
}


void scanD()
{
  for ( int count = 0; count < 8;count++ )
  {
    irSensorAnalog[count] = analogRead(irPins[count]);
////////////////////////////////////////
    if(GARIS == HITAM){
      if(irSensorAnalog[count]>KAL[count]){irSensorDigital[count] = 0; digitalWrite(irInd[count],HIGH);}
      else                                {irSensorDigital[count] = 1; digitalWrite(irInd[count],LOW);}
    }
    else{ //HITAM
      if(irSensorAnalog[count]>KAL[count]){irSensorDigital[count] = 1; digitalWrite(irInd[count],LOW);}
      else                                {irSensorDigital[count] = 0; digitalWrite(irInd[count],HIGH);}
    }
  } 
}
