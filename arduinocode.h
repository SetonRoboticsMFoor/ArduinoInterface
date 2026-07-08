const int ledPin = 3; // Pin 3 (PWM)

void setup() {
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 0); // Start OFF
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    
    if (input.length() > 0) {
      int sliderVal = input.toInt();
      sliderVal = constrain(sliderVal, 0, 255);
      
      // Gamma / Exponential correction curve: (sliderVal^2) / 255
      // This spreads out low-brightness levels across the first half of the slider
      int pwmOutput = (long)sliderVal * sliderVal / 255;
      
      analogWrite(ledPin, pwmOutput);
    }
  }
}