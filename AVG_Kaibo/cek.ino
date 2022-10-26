void cekSerial3(){
  if (Serial3.available()) {
    int dataSer3 = Serial3.parseInt();
    Serial.println(dataSer3);
    //Serial.print(" ==> ");
    if(dataSer3 > 0 && dataSer3 < 99){
      //delay(2000);
      if(SimpanData != dataSer3){
        switch(dataSer3){
          case 1 : programUtama(LINE1); break;
          case 2 : programUtama(LINE2); break;
          case 3 : programUtama(LINE3); break;
          case 4 : programUtama(LINE4); break;
          case 5 : programUtama(LINE5); break;
          case 6 : programUtama(LINE6); break;
          case 7 : programUtama(LINE7); break;
          case 8 : programUtama(LINE8); break;
          case 9 : programUtama(LINE9); break;
          case 10: programUtama(LINE10); break;
          case 11: programUtama(LINE11); break;
          case 12: programUtama(LINE12); break;
          case 13: programUtama(LINE13); break;
          case 14: programUtama(LINE14); break;
          case 15: programUtama(LINE15); break;
          case 16: programUtama(LINE16); break;
          case 17: programUtama(LINE17); break;
          case 18: programUtama(LINE18); break;
          case 19: programUtama(LINE19); break;
          case 20: programUtama(LINE20); break;
          case 21: programUtama(LINE21); break;
          case 22: programUtama(LINE22); break;
          case 23: programUtama(LINE23); break;
          case 24: programUtama(LINE24); break;
          case 25: programUtama(LINE25); break;
          case 26: programUtama(LINE26); break;
          case 27: programUtama(LINE27); break;
          case 28: programUtama(LINE28); break;
          case 29: programUtama(LINE29); break;
          case 30: programUtama(LINE30); break;
          case 31: programUtama(LINE31); break;
          case 32: programUtama(LINE32); break;
          case 33: programUtama(LINE33); break;
          case 34: programUtama(LINE34); break;
          case 35: programUtama(LINE35); break;
          case 36: programUtama(LINE36); break;
          case 37: programUtama(LINE37); break;
          case 38: programUtama(LINE38); break;
          case 39: programUtama(LINE39); break;
          case 40: programUtama(LINE40); break;
          case 41: programUtama(LINE41); break;
          case 42: programUtama(LINE42); break;
          case 43: programUtama(LINE43); break;
          case 44: programUtama(LINE44); break;
          case 45: programUtama(LINE45); break;
          case 46: programUtama(LINE46); break;
          case 47: programUtama(LINE47); break;
          case 48: programUtama(LINE48); break;
          case 49: programUtama(LINE49); break;
          case 50: programUtama(LINE50); break;
          case 98: programUtama(HOME); break;
        }
        berhenti();
        Serial3.println("2");
        StopinLine();
        //Serial.println("data masuk");
        Serial3.flush();
        delay(10000);
        Serial3.flush();
        SimpanData = dataSer3;
      }
      else{
        Serial.println("diulang");
        berhenti();
      }
    }
    else{
      berhenti();
    }
    //sprintf(dataSer,"dataMasuk %c",dataSer3);
    //Serial.println(dataSer);
  }
  else{
      berhenti();
    }
}

void cekKeypad(){
  char customKey = customKeypad.getKey();
  if (customKey){
    lcd.setCursor(0,0);
    lcd.print(customKey);
  }
}

void LEDKelip(int kali){
  for(int KM=0;KM<kali;KM++){
    for(int K=0;K<8;K++) digitalWrite(irInd[K],HIGH);
    delay(100);
    for(int K=0;K<8;K++) digitalWrite(irInd[K],LOW);
    delay(100);
  }
}

void cekLED(){
  for(int KM=0;KM<8;KM++){
  digitalWrite(irInd[KM],HIGH);
  delay(500);
  digitalWrite(irInd[KM],LOW);
  delay(500);
  }
}

void cekMotor(){
  maju(100,0);
  delay(2000);
  berhenti();
  delay(1000);
  maju(0,100);
  delay(2000);
  berhenti();
  delay(1000);
  mundur(100,0);
  delay(2000);
  berhenti();
  delay(1000);
  mundur(0,100);
  delay(2000);
  berhenti();
  delay(1000);
}

void cekSensor(){
 scanD(); 
 sprintf(dataSer,"%4d %4d %4d %4d ",irSensorAnalog[0],irSensorAnalog[1],irSensorAnalog[2],irSensorAnalog[3]);
 lcd.setCursor(0,0);
 Serial.print(dataSer);
 sprintf(dataSer,"%4d %4d %4d %4d",irSensorAnalog[4],irSensorAnalog[5],irSensorAnalog[6],irSensorAnalog[7]);
 //lcd.setCursor(0,1);
 Serial.println(dataSer);
}

void cekUS(){
// BacaUS1();
 sprintf(dataSer,"%d %d %d %d",digitalRead(Sensor1), digitalRead(Sensor2), digitalRead(Sensor3), digitalRead(Sensor4));
 lcd.setCursor(0,0);
 lcd.print(dataSer);
}

void cekRotary(){
  sprintf(dataSer,"%4d",Rot);
  lcd.setCursor(6,0);
  lcd.print(dataSer);
  Serial.println(dataSer);
}

void cekRFID(){
  while (!Serial1.available()){}
  for (byte i = 0; i < 9; i++) {    
    byteSend[i] = Serial1.read();   // Read the byte
    if(byteSend[i] != 0xFF){
      //Serial.print(byteSend[i], HEX);
      //Serial.print(" ");
    }
    else {i--;}
    //flag=1;
  }
  //if(flag == 1){Serial.println(" "); flag=0;}
  sprintf(dataRFID,"%02x %02x %02x %02x", byteSend[3], byteSend[4], byteSend[5], byteSend[6] );
  //Serial.println(dataPrint);
  lcd.setCursor(0,0);
  lcd.print(dataRFID);
  Serial1.flush();
}

void cekMotorRem(){
 remmaju();
}
