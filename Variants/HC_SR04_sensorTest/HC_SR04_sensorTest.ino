#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define SCREEN_ADDRESS 0x3C 

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

// if(!display.begin(SSD1306_I2C, 0x3C)) {
//     Serial.println(F("SSD1306 allocation failed"));
//     for(;;);
//   }

if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  delay(2000);
  display.display();
  delay(2000);

  display.clearDisplay();
}

void loop() {
  // Draw two outlined circles
  display.clearDisplay();
  
  // Circle 1
  display.drawCircle(SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2, 20, SSD1306_WHITE);

  // Circle 2
  display.drawCircle(3 * SCREEN_WIDTH / 4, SCREEN_HEIGHT / 2, 20, SSD1306_WHITE);

  // Update the display
  display.display();

  // Delay for a short period
  delay(1000);
}
