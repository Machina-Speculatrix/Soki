#include <Servo.h>

#define escPin 9

Servo esc;

int currentSpeed = 1000; // Starting speed (minimum throttle)
int targetSpeed = 1000;  // Target speed
const int minSpeed = 1000;
const int maxSpeed = 2000;
const int numSpeedLevels = 10;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Attach ESC to pin
  esc.attach(escPin);
  
  // Arm the ESC with minimum throttle
  Serial.println("Arming ESC...");
  esc.writeMicroseconds(minSpeed);  // Send minimum throttle signal
  delay(2000);  // Wait 2 seconds for arming
  Serial.println("ESC armed");
  Serial.println("Enter a speed level (1-10):");
}

void loop() {
  // Check if there is serial input available
  if (Serial.available() > 0) {
    // Read the input
    int input = Serial.parseInt();
    
    // Validate the input
    if (input >= 1 && input <= 10) {
      // Map the input to the corresponding speed
      targetSpeed = map(input, 1, 10, minSpeed, maxSpeed);
      Serial.print("Setting speed to level ");
      Serial.print(input);
      Serial.print(" (");
      Serial.print(targetSpeed);
      Serial.println(" µs)");
    } else {
      Serial.println("Invalid input. Please enter a number between 1 and 10.");
    }
  }
  
  // Gradually adjust the speed to the target speed
  if (currentSpeed < targetSpeed) {
    currentSpeed += 1; // Increase speed
  } else if (currentSpeed > targetSpeed) {
    currentSpeed -= 1; // Decrease speed
  }
  
  // Send the current speed to the ESC
  esc.writeMicroseconds(currentSpeed);
  
  // Small delay for smooth speed change
  delay(10); // Adjust delay for smoother or faster speed change
}
