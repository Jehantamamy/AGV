
void maju(int pwmki, int pwmka)
{
    analogWrite(pwm1, 0);
    analogWrite(pwm2, pwmki);
    analogWrite(pwm3, 0);
    analogWrite(pwm4, pwmka);
}

void mundur(int pwmki, int pwmka)
{
    analogWrite(pwm1,pwmki);
    analogWrite(pwm2, 0);
    analogWrite(pwm3,pwmka);
    analogWrite(pwm4, 0);
}


void remmaju()
{
    digitalWrite(pwmrem1, LOW);
    digitalWrite(pwmrem2, HIGH);

}

void remmundur()
{
    digitalWrite(pwmrem1,HIGH);
    digitalWrite(pwmrem2,LOW);
}

void remstop()
{
    digitalWrite(pwmrem1,HIGH);
    digitalWrite(pwmrem2,HIGH);
}

void remloss()
{
    digitalWrite(pwmrem1,LOW);
    digitalWrite(pwmrem2,LOW);
}

void AngkatMotor(){
  while(digitalRead(Lim)==HIGH) servoPutarKiri();
  servoStop();
  delay(500);
}

void TurunMotor(){
  servoPutarKanan();
  delay(1600);
  servoStop();
  delay(500);
}

void servoPutarKanan(){
  analogWrite(pwmser1, 100);
  analogWrite(pwmser2, 0);
}

void servoStop()
{
  analogWrite(pwmser1, 0);
  analogWrite(pwmser2, 0);
}

void servoPutarKiri(){
  analogWrite(pwmser1, 0);
  analogWrite(pwmser2, 100);
}

void berhenti(){
  analogWrite(pwm1, 0);
  analogWrite(pwm2, 0);
  analogWrite(pwm3, 0);                           
  analogWrite(pwm4, 0);
  KecepatanMotor=0; //pengereman
  PWM = 0;
}

void stopme()
{
    //Serial.println("stop");
    for (int i=KecepatanMotor; i>0; i=i-2){
      analogWrite(pwm1, i);
      analogWrite(pwm2, i);
      analogWrite(pwm3, i);                           
      analogWrite(pwm4, i);
    }
    berhenti();
}
