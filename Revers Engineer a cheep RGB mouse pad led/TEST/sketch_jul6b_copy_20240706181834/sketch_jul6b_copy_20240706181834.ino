#define BLYNK_TEMPLATE_NAME "RGB ESP"
#define BLYNK_AUTH_TOKEN "7XrSo7hTsSi0fTiwrwAHP2K0DRcr9bXo"
#define BLYNK_TEMPLATE_ID "TMPL6Znz0ZZJu"
#define BLYNK_TEMPLATE_NAME "RGB ESP"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>

// Replace with your network credentials
char ssid[] = "TAZIN 3431";
char pass[] = "143Tazin";

const int diffValue = 255;

int Red = 0;
int Green = 0;
int Blue = 0;

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

BLYNK_WRITE(V4){
  int readValue = param.asInt();
  if(readValue == 1){
   lightSlect1();
  }
}


// Blynk virtual pin write handlers
BLYNK_WRITE(V1) {
  int redValue = param.asInt();
  Serial.print("Red: ");
  Serial.println(redValue);
}

BLYNK_WRITE(V2) {
  int greenValue = param.asInt();
  Serial.print("Green: ");
  Serial.println(greenValue);
}

BLYNK_WRITE(V3) {
  int blueValue = param.asInt();
  Serial.print("Blue: ");
  Serial.println(blueValue);
}
int num = 0; 
BLYNK_WRITE(V0){
  delay(800);
  Serial.print("pressed");
  
    if (num <= 5 ){
      Blynk.virtualWrite(V4, num);
      Serial.print("++++++++");
      num++;
    }else{
      num = 0;
    }
    
  
}

void loop() {
  Blynk.run();
  
  
}