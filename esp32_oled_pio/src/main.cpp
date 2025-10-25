#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

// ST7789 240x240 Display - Working Configuration
// Wiring:
//   GND → GND
//   VCC → 3V3
//   SCL → D18 (Hardware SPI SCK)
//   SDA → D23 (Hardware SPI MOSI)
//   RES → D4  (Reset)
//   DC  → D2  (Data/Command)
//   BLK → NC  (Backlight - not connected)
// Settings: 240x240, SPI_MODE3, 4MHz

#define TFT_MOSI 23  // SDA
#define TFT_SCLK 18  // SCL
#define TFT_CS   -1  // Not connected
#define TFT_DC   2   // DC
#define TFT_RST  4   // RES

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


void setup() {
  Serial.begin(115200);
  delay(2000); 
  
  Serial.println("\n=== ST7789 240x240 Display ===");
  Serial.println("Initializing with working config:");
  Serial.println("- Resolution: 240x240");
  Serial.println("- SPI Mode: MODE3");
  Serial.println("- Speed: 4MHz");
  
  // Initialize Hardware SPI
  SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
  SPI.setFrequency(4000000);  // 4MHz - proven to work
  
  // Reset display
  pinMode(TFT_RST, OUTPUT);
  digitalWrite(TFT_RST, HIGH);
  delay(100);
  digitalWrite(TFT_RST, LOW);
  delay(100);
  digitalWrite(TFT_RST, HIGH);
  delay(200);
  
  // Initialize with working settings
  tft.init(240, 240, SPI_MODE3);
  Serial.println("Display initialized!");
  
  // Demo: Color bars
  Serial.println("\nDrawing color test...");
  tft.fillScreen(ST77XX_BLACK);
  
  int barHeight = 240 / 7;
  tft.fillRect(0, barHeight * 0, 240, barHeight, ST77XX_RED);
  tft.fillRect(0, barHeight * 1, 240, barHeight, ST77XX_ORANGE);
  tft.fillRect(0, barHeight * 2, 240, barHeight, ST77XX_YELLOW);
  tft.fillRect(0, barHeight * 3, 240, barHeight, ST77XX_GREEN);
  tft.fillRect(0, barHeight * 4, 240, barHeight, ST77XX_CYAN);
  tft.fillRect(0, barHeight * 5, 240, barHeight, ST77XX_BLUE);
  tft.fillRect(0, barHeight * 6, 240, barHeight, ST77XX_MAGENTA);
  
  delay(3000);
  
  // Demo: Text and graphics
  tft.fillScreen(ST77XX_BLACK);
  
  // Title
  tft.setTextColor(ST77XX_CYAN);
  tft.setTextSize(3);
  tft.setCursor(30, 30);
  tft.println("ST7789");
  
  // Subtitle
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(2);
  tft.setCursor(45, 70);
  tft.println("240x240");
  
  // Status
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(35, 110);
  tft.println("WORKING!");
  
  // Info
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(1);
  tft.setCursor(20, 150);
  tft.println("SPI MODE3 @ 4MHz");
  tft.setCursor(20, 165);
  tft.println("Hardware SPI");
  tft.setCursor(20, 180);
  tft.println("ESP32 WiFi Kit 32");
  
  // Border
  tft.drawRect(5, 5, 230, 230, ST77XX_WHITE);
  tft.drawRect(7, 7, 226, 226, ST77XX_MAGENTA);
  
  Serial.println("Display demo complete!");
  Serial.println("Ready for your custom code!\n");
}

void loop() {
  static int counter = 0;
  static unsigned long lastUpdate = 0;
  
  // Update display every 2 seconds
  if (millis() - lastUpdate > 2000) {
    lastUpdate = millis();
    counter++;
    
    // Update counter on display
    tft.fillRect(60, 200, 120, 25, ST77XX_BLACK);
    tft.setTextColor(ST77XX_CYAN);
    tft.setTextSize(2);
    tft.setCursor(70, 205);
    tft.print("Loop: ");
    tft.println(counter);
    
    Serial.print("Loop ");
    Serial.println(counter);
  }
  
  delay(100);
}
