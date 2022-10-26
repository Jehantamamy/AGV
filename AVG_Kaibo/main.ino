void  programUtama(String dataLine){
  TimerJalan = 1;
  lcd.setCursor(0,1);
  lcd.print(dataLine);
  while(1){
    while (!Serial1.available()){
      //BacaUS1();
      //if((distance2 == 1 && distance3 == 1) || (distance3 == 1 && distance4 == 1) || (distance4 == 1 && distance5 == 1)){
      //if(distance2 == 1 || distance3 == 1 || distance4 == 1 || distance5 == 1){
      if(digitalRead(Sensor1) == 0 || digitalRead(Sensor2) == 0 || digitalRead(Sensor3) == 0 || digitalRead(Sensor4) == 0 ){
        if(kondisi2 == 0){
          myDFPlayer.playMp3Folder(3);
          //myDFPlayer.playMp3Folder(3);
          PWM = 0;
        }
        scanD();
        KecepatanMotor=0; //pengereman
        if(KecepatanMotor<0) KecepatanMotor=0;
        PWM = 0;
        kondisi1 = 0; 
        kondisi2 = 1;
        kondisi3 = 0; 
      }
      else{ //jalan
        if(kondisi1 == 0){
          myDFPlayer.playMp3Folder(1);
          //myDFPlayer.playMp3Folder(1);
          PWM = 0;
          //TimerMusic=0;
        }
        scanD();
        //Smooth++;
        //if(Smooth > 2){
          KecepatanMotor=KecepatanMotor+5; //percepatan
        //  Smooth = 0;
        //}
        if(KecepatanMotor >  KecepatanMaksimal) KecepatanMotor=KecepatanMaksimal;
        kondisi1 = 1;
        kondisi2 = 0;
        kondisi3 = 0;
        TimerMusic++;
        if(TimerMusic >= DelayMusic){
          myDFPlayer.playMp3Folder(1);
          TimerMusic=0;
        }
      }
    }
    for (byte i = 0; i < 9; i++) {    
      byteSend[i] = Serial1.read();   // Read the byte
      if(byteSend[i] != 0xFF){
       
      }
      else {i--;}
    }
    sprintf(dataRFID,"%02x %02x %02x %02x", byteSend[3], byteSend[4], byteSend[5], byteSend[6] );
    lcd.setCursor(0,0);
    lcd.print(dataRFID);
    Serial1.flush();
    //if (strcmp(var1, "dev") == 0)
    if(String(dataRFID).equals(dataLine)) break;
  }
  berhenti();
  TimerJalan = 0;
}

void menu(){
  
}

void StopinLine(){
  if(kondisi3 == 0){
     myDFPlayer.playMp3Folder(2);
     PWM = 0;
  }
  berhenti();
  //char customKey = customKeypad.getKey();
  kondisi1 = 0;
  kondisi2 = 0;
  kondisi3 = 1;
  /*while(customKey != '*'){
    lcd.setCursor(0,0);
    lcd.print("     TEKAN *    ");
    customKey = customKeypad.getKey();
    berhenti();
  }*/
}

void cekString(int dataString){
  switch(dataString){
    case 0: LINESTOP = HOME;   break;
    case 1: LINESTOP = LINE1;  break;
    case 2: LINESTOP = LINE2;  break;
    case 3: LINESTOP = LINE3;  break;
    case 4: LINESTOP = LINE4;  break;
    case 5: LINESTOP = LINE5;  break;
    case 6: LINESTOP = LINE6;  break;
    case 7: LINESTOP = LINE7;  break;
    case 8: LINESTOP = LINE8;  break;
    case 9: LINESTOP = LINE9;  break;
    case 10: LINESTOP = LINE10;  break;
    case 11: LINESTOP = LINE11;  break;
    case 12: LINESTOP = LINE12;  break;
    case 13: LINESTOP = LINE13;  break;
    case 14: LINESTOP = LINE14;  break;
    case 15: LINESTOP = LINE15;  break;
    case 16: LINESTOP = LINE16;  break;
    case 17: LINESTOP = LINE17;  break;
    case 18: LINESTOP = LINE18;  break;
    case 19: LINESTOP = LINE19;  break;
    case 20: LINESTOP = LINE20;  break;
    case 21: LINESTOP = LINE21;  break;
    case 22: LINESTOP = LINE22;  break;
    case 23: LINESTOP = LINE23;  break;
    case 24: LINESTOP = LINE24;  break;
    case 25: LINESTOP = LINE25;  break;
    case 26: LINESTOP = LINE26;  break;
    case 27: LINESTOP = LINE27;  break;
    case 28: LINESTOP = LINE28;  break;
    case 29: LINESTOP = LINE29;  break;
    case 30: LINESTOP = LINE30;  break;
    case 31: LINESTOP = LINE31;  break;
    case 32: LINESTOP = LINE32;  break;
    case 33: LINESTOP = LINE33;  break;
    case 34: LINESTOP = LINE34;  break;
    case 35: LINESTOP = LINE35;  break;
    case 36: LINESTOP = LINE36;  break;
    case 37: LINESTOP = LINE37;  break;
    case 38: LINESTOP = LINE38;  break;
    case 39: LINESTOP = LINE39;  break;
    case 40: LINESTOP = LINE40;  break;
    case 41: LINESTOP = LINE41;  break;
    case 42: LINESTOP = LINE42;  break;
    case 43: LINESTOP = LINE43;  break;
    case 44: LINESTOP = LINE44;  break;
    case 45: LINESTOP = LINE45;  break;
    case 46: LINESTOP = LINE46;  break;
    case 47: LINESTOP = LINE47;  break;
    case 48: LINESTOP = LINE48;  break;
    case 49: LINESTOP = LINE49;  break;
    case 50: LINESTOP = LINE50;  break;
  }
}
