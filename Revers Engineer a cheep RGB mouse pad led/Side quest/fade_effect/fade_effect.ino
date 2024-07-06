// Define the pin connections for RGB
const int redPin = 0;
const int greenPin = 1;
const int bluePin = 2 ;

const int delay_amt =40 ;
const int num = 5 ;
void setup() {
  // Set the RGB pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //cycleColors();

  
}

void loop() {

  cycleColors();
  for (int i = 255; i >= 0; i -= num) {
    setColor(i, 255, i);  // Fade blue out
    delay(delay_amt);
  }
  for (int i = 0; i <= 255; i += num) {
    setColor(i, 255, i);  // Fade blue in
    delay(delay_amt);
  }
  cycleColors();
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

