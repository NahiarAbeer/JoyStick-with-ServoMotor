#include<Servo.h>

Servo X;
Servo Y;
const int swPin = 2;
const int xPin = 8;
const int yPin = 10;
const int X_PIN = A0;
const int Y_PIN = A1;
const int LED = 6;
bool ledState = false;


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  X.attach(xPin);
  Y.attach(yPin);
  X.write(90);   // Start servo 1 at center
  Y.write(90);   // Start servo 2 at center
  pinMode(swPin, INPUT_PULLUP);

}

void loop() {
  // Read 10-bit ADC values
  int xValue = analogRead(X_PIN);
  int yValue = analogRead(Y_PIN);

  // Convert 0–1023 to 0–180 degrees
  int xDegree = map(xValue, 0, 1023, 0, 180);
  int yDegree = map(yValue, 0, 1023, 0, 180);
  bool pressed = (digitalRead(swPin) == LOW);

  if (pressed) {
    ledState = !ledState;              // Toggle LED state
    digitalWrite(LED, ledState ? HIGH : LOW);  
  }
  X.write(xDegree);
  Y.write(yDegree);
  // Print results
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" -> ");
  Serial.print(xDegree);
  Serial.print("°    ");

  Serial.print("Y: ");
  Serial.print(yValue);
  Serial.print(" -> ");
  Serial.print(yDegree);
  Serial.println("°");

  delay(100);
}