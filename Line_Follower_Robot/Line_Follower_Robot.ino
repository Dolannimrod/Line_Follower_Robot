// Define pin numbers for sensor inputs
const int leftSensorPin = 2;   // Left sensor connected to digital pin 2
const int rightSensorPin = 3;  // Right sensor connected to digital pin 3

// Define pin numbers for motor outputs
const int leftMotorPin = 4;    // Left motor connected to digital pin 4
const int rightMotorPin = 5;   // Right motor connected to digital pin 5

// Define threshold values for sensor readings
const int threshold = 500;     // Adjust this value according to your environment

void setup() {
  // Initialize sensor pins as inputs
  pinMode(leftSensorPin, INPUT);
  pinMode(rightSensorPin, INPUT);

  // Initialize motor pins as outputs
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
}

void loop() {
  int leftSensorValue = analogRead(leftSensorPin);   // Read left sensor
  int rightSensorValue = analogRead(rightSensorPin); // Read right sensor

  // Determine the movement direction based on sensor readings
  if (leftSensorValue > threshold && rightSensorValue > threshold) {
    // Both sensors see the line, move forward
    digitalWrite(leftMotorPin, HIGH);
    digitalWrite(rightMotorPin, HIGH);
  } else if (leftSensorValue > threshold) {
    // Only left sensor sees the line, turn right
    digitalWrite(leftMotorPin, LOW);
    digitalWrite(rightMotorPin, HIGH);
  } else if (rightSensorValue > threshold) {
    // Only right sensor sees the line, turn left
    digitalWrite(leftMotorPin, HIGH);
    digitalWrite(rightMotorPin, LOW);
  } else {
    // Both sensors do not see the line, stop
    digitalWrite(leftMotorPin, LOW);
    digitalWrite(rightMotorPin, LOW);
  }
}
