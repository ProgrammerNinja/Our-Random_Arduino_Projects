#define BLYNK_TEMPLATE_NAME "RGB ESP"
#define BLYNK_AUTH_TOKEN "7XrSo7hTsSi0fTiwrwAHP2K0DRcr9bXo"
#define BLYNK_TEMPLATE_ID "TMPL6Znz0ZZJu"
#define BLYNK_TEMPLATE_NAME "RGB ESP"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>

// Replace with your network credentials
char ssid[] = "IT";
char pass[] = "TazinSayeed!@#";
int redPin = 0;
int greenPin = 0;
int bluePin = 0;

//global variables
  int sw = 0;
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
// Function to set the color of the RGB LEDs
void setColor(int red, int green, int blue) {
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
void checkBlynkStatus() { // called every 2 seconds by SimpleTimer

  bool isconnected = Blynk.connected();
  if (isconnected == false) {
    Serial.println("Blynk Not Connected");
  }
  if (isconnected == true) {
    setColor(0, 0, 255);
  }
}
/////////////////////////////////////////////////
//Functions

void randomColor(){
  for(int i = 255; i <= 0; i -=5){
    long randNumberR = random(256);
    delay(10);
    long randNumberG = random(256);
    delay(10);
    long randNumberB = random(256);
    delay(10);
    setColor(int(randNumberR), int(randNumberG), int(randNumberB));
    delay(30);
  }
}


// Function to cycle through basic colors
void cycleColors() {

  setColor(255, 0, 0);  // Red
  delay(1000);
  setColor(0, 255, 0);  // Green
  delay(1000);
  setColor(0, 0, 255);  // Blue
  delay(1000);
  setColor(255, 255, 0);  // Yellow
  delay(1000);
  setColor(0, 255, 255);  // Cyan
  delay(1000);
  setColor(255, 0, 255);  // Magenta
  delay(1000);
  setColor(255, 255, 255);  // White
  delay(1000);

}
int v1;
int v2;
int v3;
// Function to fade colors in and out
void fadeColors(int x, int y, int z) {
  int v1 = x;
  int v2 = y;
  int v3 = z;
  int i = 0;
  if (v1 <= 0 && v2 <= 0 && v3 <= 0 && sw == 0){
    setColor(v1, v2, v3);
    v1 = v1 - 5;
    v2 = v2 - 5;
    v3 = v3 - 5;
    if( v1 <= 0){
      v1 = 0;
    }
    if (v2 <= 0){
      v2 = 0;
    }
    if (v3 <= 0){
      v3 = 0;
    }
    if(v1 == 0 && v2 ==0 && v3 == 0){
      sw = 1;
    }
      
    delay(20);
    Serial.println(v1);
  }
  if (v1 != x && v2 != y && v3 != z){
    setColor(v1, v2, v3);
    v1 = v1 + 5;
    v2 = v2 + 5;
    v3 = v3 + 5;
    if( v1 >= x){
      v1 = x;
    }
    if (v2 >= y){
      v2 = y;
    }
    if (v3 >= z){
      v3 = z;
    }
    if(v1 == x && v2 == y && v3 == z){
      sw = 0;
      }
      

    delay(20);
    Serial.println(v1);
  }
 
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
  greenValue = readValue;
}
BLYNK_WRITE(V3){
  int readValue = param.asInt();
  blueValue = readValue;
}
BLYNK_WRITE(V4){
  int readValue = param.asInt();
  seqValue = readValue;
}

  



void setup() {
  // Debug console
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){

    Serial.print("Connecting to WiFi..");
    Serial.println(ssid);
    //setColor(255, 0, 0);
  }
  timer.setInterval(2000L, checkBlynkStatus); // check if Blynk server is connected every 2 seconds
  Blynk.config(BLYNK_AUTH_TOKEN);
  setColor(0, 255, 0);
  delay(500);// WAIT FOR HALF SECONDS


  cycleColors();

}
void loop() {
  Blynk.run();
  if (seqValue == 1 && functionValue == 1){
    Serial.println("Setting Value for Color 1:");
    r1 = redValue;
    Serial.print("Red= ");
    Serial.println(r1);
    g1 = greenValue;
    Serial.print("Green= ");
    Serial.println(g1);
    b1 = blueValue;
    Serial.print("Blue= ");
    Serial.println(b1);
    
  }
  if(seqValue == 2 && functionValue == 1){

    Serial.println("Setting Value for Color 2:");
    r2 = redValue;
    Serial.print("Red= ");
    Serial.println(r2);
    g2 = greenValue;
    Serial.print("Green= ");
    Serial.println(g2);
    b2 = blueValue;
    Serial.print("Blue= ");
    Serial.println(b2);
    
    
  }
  if(seqValue == 3 && functionValue == 1){

    Serial.println("Setting Value for Color 3:");
    r3 = redValue;
    Serial.print("Red= ");
    Serial.println(r3);
    g3 = greenValue;
    Serial.print("Green= ");
    Serial.println(g3);
    b3 = blueValue;
    Serial.println("Blue= ");
    Serial.println(b3);
    
  }
   if(seqValue == 4 && functionValue == 1){
      Serial.println("Setting Value for Color 4:");
      r4 = redValue;
      Serial.print("Red= ");
      Serial.println(r4);
      g4 = greenValue;
      Serial.print("Green= ");
      Serial.println(g4);
      b4 = blueValue;
      Serial.print("Blue= ");
      Serial.println(b4);
    
  }
   if(seqValue == 5 && functionValue == 1 ){
      Serial.println("Setting Value for Color 5:");
      r5 = redValue;
      Serial.print("Red= ");
      Serial.println(r5);
      g5 = greenValue;
      Serial.print("Green= ");
      Serial.println(g5);
      b5 = blueValue;
      Serial.print("Blue= ");
      Serial.println(b5);
    }

  if (seqValue == 0 && functionValue == 1 ){
    fadeColors(r1, g1, b1);
    fadeColors(r2, g2, b2);
    fadeColors(r3, g3, b3);
    fadeColors(r4, g4, b4);
    fadeColors(r5, g5, b5);
    /*Serial.println(r1);
    Serial.println(r2);
    Serial.println(r3);
    Serial.println(g2);
    Serial.println(g2);
*/
    Serial.println("on");
  }
  
 
}






