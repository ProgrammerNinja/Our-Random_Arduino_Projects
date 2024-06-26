// Define the pin connections for RGB
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;



void setup() {
  Serial.begin(9600);
  Serial.print("initing....");
  // Set the RGB pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  
}

void loop() {
  cycleColors();
   for (int i = 255; i >= 0; i -= 5) {
    setColor(0, i, 0);  // Fade blue out
    delay(30);
  }
 


// Function to cycle through basic colors
void cycleColors() {

  setColor(0, 255, 255);  // Red
  delay(1000);
  setColor(255, 0, 255);  // Green
  delay(1000);
  setColor(255, 255, 0);  // Blue
  delay(1000);
  setColor(0, 0, 255);  // Yellow
  delay(1000);
  setColor(255, 0, 0);  // Cyan
  delay(1000);
  setColor(0, 255, 0);  // Magenta
  delay(1000);
  setColor(0, 0, 0);  // White
  delay(1000);

}





// Function to set the color of the RGB LEDs
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

