#include <Wire.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);

  // Initialize MPU6050
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1);
  }

  Serial.println("MPU6050 initialized successfully!");

  // Calibrate MPU6050
  calibrateMPU6050();
}

void loop() {
  // Read calibrated MPU6050 data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Calculate orientation
  float roll = atan2(a.acceleration.y, a.acceleration.z) * 180.0 / PI;
  float pitch = atan2(-a.acceleration.x, sqrt(a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z)) * 180.0 / PI;

  // Print calibrated results
  Serial.print("Calibrated Roll: ");
  Serial.print(roll);
  Serial.print(" | Calibrated Pitch: ");
  Serial.println(pitch);

  delay(1000);  // Adjust delay based on your application's needs
}

// Function to calibrate MPU6050
void calibrateMPU6050() {
  Serial.println("Starting MPU6050 calibration. Please keep the sensor flat and stable.");

  delay(3000);  // Allow time to stabilize

  // Variables to store initial readings
  float initialX = 0.0;
  float initialY = 0.0;
  float initialZ = 0.0;

  // Read initial readings for a short duration
  for (int i = 0; i < 100; i++) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    initialX += a.acceleration.x;
    initialY += a.acceleration.y;
    initialZ += a.acceleration.z;

    delay(10);
  }

  // Calculate average initial readings
  initialX /= 100.0;
  initialY /= 100.0;
  initialZ /= 100.0;

  // Print calibration offsets
  Serial.println("Calibration complete. Please use the following offsets in your code:");
  Serial.print("float offsetX = ");
  Serial.print(-initialX);  // Reverse sign if needed
  Serial.println(";");
  Serial.print("float offsetY = ");
  Serial.print(-initialY);  // Reverse sign if needed
  Serial.println(";");
  Serial.print("float offsetZ = ");
  Serial.print(-initialZ);  // Reverse sign if needed
  Serial.println(";");
}
