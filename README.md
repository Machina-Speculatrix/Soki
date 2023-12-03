# Soki
A two-wheeled self-balancing robot with an object avoidance feature.

This repo contains the programs used for my mini robot meant for desktop with features such as self-balancing using MPU6050, and object avoidance using ultrasonic sensor SR04. 

The complete project involves items, such as:

- Arduino Nano
- HC-SR04
- mpu6050
- Mini L298n motor driver
- Two LI-ion battery(from old laptop setup)
- BO motors 150RPM
- Two mini wheels
- Mini aluminum framed, self-designed.
- Nuts, bolts and screws
- connecting wires

~VARIANTS:

This folder includes a test script for both the MPU6050 and the HC-SR04 ultrasonic sensor, you can upload each script once and note the result to test your parts.

  /- The HC-SR04 sensor test: This Program is meant to check the distance, set the serial monitor baud rate at 9600, and test it. It should give the distance between itself and the object in front
  
  
  /- MPU6050_roll-pitch: This program i supposed to give the value of the roll and pitch of the mpu6050, make sure it changes according to the orientation you put it into. 
  
  
  /- MPU6050 calibration: This is an **IMPORTANT** program, it will give the calibrated value for the mpu6050, make sure to keep the mpu6050 horizontal to get a calibrated value, once you get that
     you need to replace the same values in the main program of  the robot at **CalibratedX, CalibratedY, CalibratedZ** this program is necessary for the robot, to run the program, just upload it to your Arduino, and check
     the Serial monitor



~THE PROJECTS:

The project starts with designing the frame and attaching the BO motors making a platform for the Electronics, soldering connecting ribbon wires to the motors, and connecting the PCB to the motor driver. 
