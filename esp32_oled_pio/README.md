ESP32 SSD1351 OLED (PlatformIO)

This is a minimal PlatformIO project for ESP32 (esp32dev) using the Adafruit SSD1351 driver (SPI) and Adafruit GFX.

Wiring (example pins used in `src/main.cpp`):
- MOSI -> GPIO23
- MISO -> GPIO19
- SCLK -> GPIO18
- CS   -> GPIO5
- DC   -> GPIO16
- RST  -> GPIO17
- VCC  -> 3.3V
- GND  -> GND

Notes:
- Avoid using pins that change boot mode (GPIO0, GPIO2, GPIO15) for CS/DC/RST if possible.
- Adjust pin defines in `src/main.cpp` to match your wiring.

Build & upload (from the project root):

  pio run -d "./esp32_oled_pio" -e esp32dev -t upload --upload-port /dev/cu.usbserial-XXXX

Open serial monitor:

  pio device monitor -d "./esp32_oled_pio" -e esp32dev --port /dev/cu.usbserial-XXXX

If you prefer to open the project in VS Code, open the `esp32_oled_pio` folder and use PlatformIO's UI to build and upload.
