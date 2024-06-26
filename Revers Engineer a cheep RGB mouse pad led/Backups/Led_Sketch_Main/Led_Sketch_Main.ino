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
  Serial.println("...");
  int rand = randomSeed(analogRead(A0));
  setColor(rand);
  cycleColors();
  // Blending colors
  blendColors();
  blendColors();

  // Fading effect
  fadeColors();
  fadeColors();

  // Flashing pattern
  flashPattern();
  flashPattern();
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

// Function to blend colors
void blendColors() {
 
  for (int r = 0; r <= 255; r += 5) {
    for (int g = 0; g <= 255; g += 5) {
      for (int b = 0; b <= 255; b += 5) {
        setColor(r, g, b);
        delay(20);
      }
    }
  }
}

// Function to fade colors in and out
void fadeColors() {

  for (int i = 0; i <= 255; i += 5) {
    setColor(i, 0, 0);  // Fade red in
    delay(30);
  }
  for (int i = 255; i >= 0; i -= 5) {
    setColor(i, 0, 0);  // Fade red out
    delay(30);
  }
  for (int i = 0; i <= 255; i += 5) {
    setColor(0, i, 0);  // Fade green in
    delay(30);
  }
  for (int i = 255; i >= 0; i -= 5) {
    setColor(0, i, 0);  // Fade green out
    delay(30);
  }
  for (int i = 0; i <= 255; i += 5) {
    setColor(0, 0, i);  // Fade blue in
    delay(30);
  }
  for (int i = 255; i >= 0; i -= 5) {
    setColor(0, 0, i);  // Fade blue out
    delay(30);
  }
}

// Function to create a flashing pattern
void flashPattern() {
  for (int i = 0; i < 5; i++) {
    setColor(255, 0, 0);  // Flash red
    delay(200);
    setColor(0, 0, 0);  // Turn off
    delay(200);
    setColor(0, 255, 0);  // Flash green
    delay(200);
    setColor(0, 0, 0);  // Turn off
    delay(200);
    setColor(0, 0, 255);  // Flash blue
    delay(200);
    setColor(0, 0, 0);  // Turn off
    delay(200);
  }
}

// Function to set the color of the RGB LEDs
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

