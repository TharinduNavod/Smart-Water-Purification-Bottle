#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "GravityTDS.h"

// TDS Sensor
#define TdsSensorPin 34
GravityTDS gravityTds;
float temperature = 25;
float tdsValue = 0;

// OLED Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// FreeRTOS task handles
TaskHandle_t TdsTaskHandle;
TaskHandle_t OledTaskHandle;

// Convert TDS to water clarity
String getWaterClarity(float tds) {
  if (tds < 50) return "Excellent";
  else if (tds < 150) return "Good";
  else if (tds < 300) return "Fair";
  else if (tds < 500) return "Poor";
  else return "Very Poor";
}

// TDS Reading Task
void TdsTask(void *pvParameters) {
  for (;;) {
    gravityTds.setTemperature(temperature);  // temperature compensation
    gravityTds.update();
    tdsValue = gravityTds.getTdsValue();
    vTaskDelay(pdMS_TO_TICKS(1000)); // 1 second
  }
}

// OLED Display Task
void OledTask(void *pvParameters) {
  for (;;) {
    String clarity = getWaterClarity(tdsValue);

    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.println("Water TDS:");
    display.setCursor(0, 25);
    display.println(String(tdsValue,0) + " ppm");
    display.setCursor(0, 50);
    display.println("Clarity: " + clarity);
    display.display();

    // Serial output
    Serial.print("TDS: "); Serial.print(tdsValue,0); Serial.print(" ppm, ");
    Serial.println("Clarity: " + clarity);

    vTaskDelay(pdMS_TO_TICKS(1000)); // 1 second
  }
}

void setup() {
  Serial.begin(115200);

  // Initialize TDS
  gravityTds.setPin(TdsSensorPin);
  gravityTds.setAref(3.3);
  gravityTds.setAdcRange(4096);  // ESP32 12-bit ADC
  gravityTds.begin();

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();

  // Create FreeRTOS tasks
  xTaskCreate(TdsTask, "TDS Task", 2048, NULL, 1, &TdsTaskHandle);
  xTaskCreate(OledTask, "OLED Task", 4096, NULL, 1, &OledTaskHandle);
}

void loop() {
  // Empty: FreeRTOS tasks handle everything
}
