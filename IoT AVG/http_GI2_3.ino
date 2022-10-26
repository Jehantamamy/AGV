#include <HTTPClient.h>

#include <WiFi.h>

const char* ssid     = "OPPO Reno5";
const char* password = "sulis123";
#define STANDBY 0
#define JALAN 1
#define LINE 2
#define HOME 3



char statkirim; int statterima; char rstat=STANDBY;
String payload;

HTTPClient http;

void setup() {
  // put your setup code here, to run once:
  Serial2.begin(9600); 
  Serial.begin(9600);
  pinMode(2,OUTPUT); //pin flag sudah baca rfid
  pinMode(3,OUTPUT);
  digitalWrite(2,LOW);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(2,HIGH);
  
  delay(1000);
  http.begin("https://192.168.10.3/smartagv/robot/gedek/target"); //Specify the URL
      int httpCode = http.GET();
      if (httpCode > 0) {
        payload = http.getString();
        if (payload=="STANDBY")rstat=STANDBY;
        else if (payload=="HOME")rstat=STANDBY; //jatah ganti HOME
        else if (payload=="STOP")rstat=LINE;
        else {
          rstat=JALAN;
          statkirim=payload.toInt();
          Serial2.println(payload);
        }
        Serial.println(rstat);
        }
}

void loop() {
//  if (Serial2.available())
//{
//  statterima=Serial2.read();
//  Serial.write(statterima);
//  
//} 

//Serial2.println("10");
  if (WiFi.status() != WL_CONNECTED){
    WiFi.begin(ssid, password);
    delay(1000);
  }
  if (rstat==STANDBY){
    Serial2.println("0");
      http.begin("https://192.168.10.3/smartagv/robot/gedek/target"); //Specify the URL
      int httpCode = http.GET();
      if (httpCode > 0) {
        payload = http.getString();
        statkirim=payload.toInt();
        if (statkirim>0 && statkirim<99){
          Serial2.println(payload);
    
          rstat=JALAN;
          Serial.println("jalan");
        }
      }
  }
  else if (rstat==JALAN){
    Serial2.println(payload);
    while (Serial2.available()){
    statterima= Serial2.parseInt();
    Serial.print(statterima);
    if (statterima==2){ //standby
      payload="99";
      Serial2.println("99");
      http.begin("https://192.168.10.3/smartagv/robot/gedek/tembak");
      http.GET();
      //http.end();
      rstat=LINE;
      Serial.println("line");
      //Serial2.flush();
      
    }
    }
  }
  else if (rstat==LINE){
    http.begin("https://192.168.10.3/smartagv/robot/gedek/target"); //Specify the URL
      int httpCode = http.GET();
      if (httpCode > 0) {
        payload = http.getString();
        if (payload=="HOME"){
          Serial2.println("98");
          rstat=HOME;
          Serial.println("home");
        }
        else if (payload=="STOP")
        {Serial2.println("99");}
        else {
          //Serial.println(payload);
          statkirim=payload.toInt();
          //if (statkirim>0 && statkirim<99){
          Serial2.println(payload);
          rstat=JALAN;
          Serial.println("jalan");
        //}
        }
      }
      else {Serial.println("error");}
      //http.end();
  }
  else if (rstat==HOME){
    if (Serial2.available()>0){
    statterima= Serial2.read();
    if (statterima=='2'){ //standby
      http.begin("https://192.168.10.3/smartagv/robot/gedek/tembak");
      http.GET();
      rstat==STANDBY;
      Serial.println("standby");
    }
    }
  }
  
  
}
