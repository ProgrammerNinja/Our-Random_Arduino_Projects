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
int greenPin = 1;
int bluePin = 2;

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
const int Fdelay = 20;
//values from slider
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int seqValue = 0 ;
int initialRed, initialGreen, initialBlue;
int functionValue = 0;
bool decreasing = false;
 
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
    ////Serial.println("Blynk Not Connected");
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
  setColor(0, 0, 0);

}

// Function to fade colors in and out
void fadeColors(int initialRed, int initialGreen, int initialBlue, int redValueQ, int greenValueQ, int blueValueQ) {
  
  while (decreasing == false && functionValue == 1) {
    if (redValueQ < initialRed) redValueQ += 5;
    if (greenValueQ < initialGreen) greenValueQ += 5;
    if (blueValueQ < initialBlue) blueValueQ += 5;
    setColor(redValueQ, greenValueQ, blueValueQ);
    Blynk.syncVirtual(V4); // Sync the value of V4
    Blynk.run();
    if (redValueQ > initialRed) redValueQ = initialRed;
    if (greenValueQ > initialGreen) greenValueQ = initialGreen;
    if (blueValueQ > initialBlue) blueValueQ = initialBlue;
    delay(Fdelay);
    if (redValueQ == initialRed && greenValueQ == initialGreen && blueValueQ == initialBlue) {
      decreasing = true;
    }
    

    //Serial.print("Red: ");
  //Serial.println(redValueQ);
  //Serial.print("Green: ");
  //Serial.println(greenValueQ);
  //Serial.print("Blue: ");
  //Serial.println(blueValueQ);
  }
  while (decreasing == true && functionValue == 1) {
    if (redValueQ > 0) redValueQ -= 5;
    if (greenValueQ > 0) greenValueQ -= 5;
    if (blueValueQ > 0) blueValueQ -= 5;
    setColor(redValueQ, greenValueQ, blueValueQ);
    Blynk.syncVirtual(V4); // Sync the value of V4
    Blynk.run();
    if (redValueQ < 0) redValueQ = 0;
    if (greenValueQ < 0) greenValueQ = 0;
    if (blueValueQ < 0) blueValueQ = 0;
    delay(Fdelay);
    if (redValueQ == 0 && greenValueQ == 0 && blueValueQ == 0) {
      decreasing = false;
    }
    

    //Serial.print("Red: ");
    //Serial.println(redValueQ);
    //Serial.print("Green: ");
    //Serial.println(greenValueQ);
    //Serial.print("Blue: ");
    //Serial.println(blueValueQ);
  } 
  
 
}


BLYNK_WRITE(V0){
  int readValue = param.asInt();
  functionValue = readValue;
  
}
BLYNK_WRITE(V1){
  int readValue = param.asInt();
  redValue = readValue;
  int mValue = 255 - redValue;
  analogWrite(redPin, mValue);
  
}
BLYNK_WRITE(V2){
  int readValue = param.asInt();
  greenValue = readValue;
  int mValue = 255 - greenValue;
  analogWrite(greenPin, mValue);
}
BLYNK_WRITE(V3){
  int readValue= param.asInt();
  blueValue = readValue;
  int mValue = 255 - blueValue;
  analogWrite(bluePin, mValue);
}
BLYNK_WRITE(V4){
  int readValue = param.asInt();
  seqValue = readValue;
  
}

  



void setup() {
  // Debug console
  //Serial.begin(115200);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  WiFi.begin(ssid, pass);
  setColor(255, 0, 0);
  while (WiFi.status() != WL_CONNECTED){

    //Serial.print("Connecting to WiFi..");
    //Serial.println(ssid);
    delay(500);
  }
  setColor(0, 0, 255);
  delay(1000);
  timer.setInterval(2000L, checkBlynkStatus); // check if Blynk server is connected every 2 seconds
  Blynk.config(BLYNK_AUTH_TOKEN);
  setColor(0, 255, 0);
  delay(1000);
  delay(500);// WAIT FOR HALF SECONDS


  cycleColors();

}
void loop() {
  Blynk.run();
  if (seqValue == 1 && functionValue == 1){
    //Serial.println("Setting Value for Color 1:");
    r1 = redValue;
    //Serial.print("Red= ");
    //Serial.println(r1);
    g1 = greenValue;
    //Serial.print("Green= ");
    //Serial.println(g1);
    b1 = blueValue;
    //Serial.print("Blue= ");
    //Serial.println(b1);
    
  }
  if(seqValue == 2 && functionValue == 1){

    //Serial.println("Setting Value for Color 2:");
    r2 = redValue;
    //Serial.print("Red= ");
    //Serial.println(r2);
    g2 = greenValue;
    //Serial.print("Green= ");
    //Serial.println(g2);
    b2 = blueValue;
    //Serial.print("Blue= ");
    //Serial.println(b2);
    
    
  }
  if(seqValue == 3 && functionValue == 1){

    //Serial.println("Setting Value for Color 3:");
    r3 = redValue;
    //Serial.print("Red= ");
    //Serial.println(r3);
    g3 = greenValue;
    //Serial.print("Green= ");
    //Serial.println(g3);
    b3 = blueValue;
    //Serial.println("Blue= ");
    //Serial.println(b3);
    
  }
   if(seqValue == 4 && functionValue == 1){
      //Serial.println("Setting Value for Color 4:");
      r4 = redValue;
      //Serial.print("Red= ");
      //Serial.println(r4);
      g4 = greenValue;
      //Serial.print("Green= ");
      //Serial.println(g4);
      b4 = blueValue;
      //Serial.print("Blue= ");
      //Serial.println(b4);
    
  }
   if(seqValue == 5 && functionValue == 1 ){
      //Serial.println("Setting Value for Color 5:");
      r5 = redValue;
      //Serial.print("Red= ");
      //Serial.println(r5);
      g5 = greenValue;
      //Serial.print("Green= ");
      //Serial.println(g5);
      b5 = blueValue;
      //Serial.print("Blue= ");
      //Serial.println(b5);
    }

  if (seqValue == 0 && functionValue == 1 ){
    fadeColors(r1, g1, b1, 0, 0, 0);
    fadeColors(r2, g2, b2, 0, 0, 0);
    fadeColors(r3, g3, b3, 0, 0, 0);
    fadeColors(r4, g4, b4, 0, 0, 0);
    fadeColors(r5, g5, b5, 0, 0, 0);
    /*//Serial.println(r1);
    //Serial.println(r2);
    //Serial.println(r3);
    //Serial.println(g2);
    //Serial.println(g2);
*/
    //Serial.println("on");
  }
  if (functionValue == 0){
    setColor(0, 0, 0);
    delay(500);
  }
  
 
}






