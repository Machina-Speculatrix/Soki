#include <NewPing.h>

// Initialize HC-SR04 object
NewPing sonar(7, 8);  // Trig pin, Echo pin

void setup() {
  Serial.begin(9600);
  Serial.println("HC-SR04 Distance Measurement");
}

void loop() {
  // Read distance from HC-SR04
  unsigned int distance = sonar.ping_cm();

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);  // Adjust delay based on your application's needs
}
