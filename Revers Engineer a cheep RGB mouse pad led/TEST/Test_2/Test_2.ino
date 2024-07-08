#define BLYNK_TEMPLATE_NAME "RGB ESP"
#define BLYNK_AUTH_TOKEN "7XrSo7hTsSi0fTiwrwAHP2K0DRcr9bXo"
#define BLYNK_TEMPLATE_ID "TMPL6Znz0ZZJu"
#define BLYNK_TEMPLATE_NAME "RGB ESP"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>

// Replace with your network credentials
char ssid[] = "test";
char pass[] = "12345678";

const int diffValue = 255;

int Red = 0;
int Green = 0;
int Blue = 0;

//global variables
//1st sequence
int r1 = 0;
int g1 = 0;
int b1 = 0;
//2n sequence 
int r2 = 0;
int g2 = 0;
int b2 = 0;
//3rd sequence
int r3 = 0;
int g3 = 0;
int b3 = 0;
//4th sequence
int r4 = 0;
int g4 = 0;
int b4 = 0;
//5th sequence
int r5 = 0;
int g5 = 0;
int b5 = 0;
//values from slider
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int seqValue = 0 ;
int functionValue = 0;





bool fetch_blynk_state = true;  //true or false

BlynkTimer timer;

void checkBlynkStatus() { // called every 2 seconds by SimpleTimer

  bool isconnected = Blynk.connected();
  if (isconnected == false) {
    Serial.println("Blynk Not Connected");
  }
  if (isconnected == true) {
  }
}
void setup() {
  // Debug console
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){

    Serial.print("Connecting to WiFi..");
    Serial.println(ssid);
  }
  timer.setInterval(2000L, checkBlynkStatus); // check if Blynk server is connected every 2 seconds
  Blynk.config(BLYNK_AUTH_TOKEN);
  delay(500);// WAIT FOR HALF SECONDS

}
BLYNK_WRITE(V0){
  int readValue = param.asInt();
  functionValue = readValue;
}
BLYNK_WRITE(V1){
  int readValue = param.asInt();
  redValue = readValue;
}
BLYNK_WRITE(V2){
  int readValue = param.asInt();
  greenValue = readValue ;
}
BLYNK_WRITE(V3){
  int readValue = param.asInt();
  blueValue = readValue ;
}
BLYNK_WRITE(V4){
  int readValue = param.asInt();
  seqValue = readValue;
}
void seqFunction(){
  if (seqValue == 1){
    if (r1 != redValue || g1 != greenValue || b1 != blueValue){
      Serial.println("Setting Value for Color 1:");
      r1 = redValue;
      Serial.println("Red= ");
      Serial.print(r1);
      g1 = greenValue;
      Serial.println("Green= ");
      Serial.print(g1);
      b1 = blueValue;
      Serial.println("Blue= ");
      Serial.print(b1);
    }
    
  }else if(seqValue == 2){
    if (r2 != redValue || g2 != greenValue || b2 != blueValue){
      Serial.println("Setting Value for Color 2:");
      r2 = redValue;
      Serial.println("Red= ");
      Serial.print(r2);
      g2 = greenValue;
      Serial.println("Green= ");
      Serial.print(g2);
      b2 = blueValue;
      Serial.println("Blue= ");
      Serial.print(b2);
    }
    
  }else if(seqValue == 3){
    if (r3 != redValue || g3 != greenValue || b3 != blueValue){
      Serial.println("Setting Value for Color 3:");
      r3 = redValue;
      Serial.println("Red= ");
      Serial.print(r3);
      g3 = greenValue;
      Serial.println("Green= ");
      Serial.print(g3);
      b3 = blueValue;
      Serial.println("Blue= ");
      Serial.print(b3);
    }
    
  }else if(seqValue == 4){
    if (r4 != redValue || g4 != greenValue || b4 != blueValue){
      Serial.println("Setting Value for Color 4:");
      r4 = redValue;
      Serial.println("Red= ");
      Serial.print(r4);
      g4 = greenValue;
      Serial.println("Green= ");
      Serial.print(g4);
      b4 = blueValue;
      Serial.println("Blue= ");
      Serial.print(b4);
    }
    
  }else if(seqValue == 5){
    if (r5 != redValue || g5 != greenValue || b5 != blueValue){
      Serial.println("Setting Value for Color 5:");
      r5 = redValue;
      Serial.println("Red= ");
      Serial.print(r5);
      g5 = greenValue;
      Serial.println("Green= ");
      Serial.print(g5);
      b5 = blueValue;
      Serial.println("Blue= ");
      Serial.print(b5);
    } 
  }else {
    if(seqValue != 0){Serial.println("Invalid Sequence Number.....");}
  }
}


void loop() {
  Blynk.run();
  seqFunction();
  
  
}