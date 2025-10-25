# ST7789 Display Wiring Diagram for WiFi Kit 32

## Connection Table

| ST7789 Display Pin | Wire To | WiFi Kit 32 Pin | GPIO Number |
|-------------------|---------|-----------------|-------------|
| **GND**           | →       | GND             | Ground      |
| **VCC**           | →       | 3V3             | 3.3V Power  |
| **SCL** (Clock)   | →       | OLED_SCL        | GPIO15      |
| **SDA** (MOSI)    | →       | OLED_SDA        | GPIO4       |
| **RES** (Reset)   | →       | OLED_RST        | GPIO16      |
| **DC**            | →       | (not used)      | -1          |
| **CS**            | →       | (not used)      | -1          |
| **BLK** (Backlight)| →      | 3V3             | 3.3V Power  |

## Visual Wiring Diagram

```
    ST7789 Display                    WiFi Kit 32 Board
    ┌──────────────┐                 ┌──────────────────┐
    │              │                 │                  │
    │   GND   ○────┼─────────────────┼─○ GND           │
    │   VCC   ○────┼─────────────────┼─○ 3V3           │
    │   SCL   ○────┼─────────────────┼─○ GPIO15        │
    │   SDA   ○────┼─────────────────┼─○ GPIO4         │
    │   RES   ○────┼─────────────────┼─○ GPIO16        │
    │   DC    ○    │   (not used)    │                  │
    │   CS    ○    │   (not used)    │                  │
    │   BLK   ○────┼─────────────────┼─○ 3V3           │
    │              │                 │                  │
    └──────────────┘                 └──────────────────┘
```

## Pin Configuration in Code

```cpp
#define OLED_SDA  4   // Data pin  (ST7789 SDA/MOSI)
#define OLED_SCL  15  // Clock pin (ST7789 SCL/SCK)
#define OLED_RST  16  // Reset pin (ST7789 RES/RST)
#define OLED_DC   -1  // DC not used (software SPI handles it)
#define OLED_CS   -1  // CS not used (software SPI handles it)
```

## Important Notes

1. **Power Supply**: Connect VCC and BLK (backlight) to 3.3V (3V3 pin)
2. **Ground**: Connect GND to GND
3. **Data Pins**: 
   - SDA (data) → GPIO4
   - SCL (clock) → GPIO15
   - RST (reset) → GPIO16
4. **Unused Pins**: DC and CS are handled by software SPI, set to -1 in code
5. **Display Type**: Code is configured for ST7789 240x240 display
6. **SPI Mode**: Using software SPI (bit-banging) on the specified pins

## Testing

After wiring, the display should show:
1. RED screen (1 second)
2. GREEN screen (1 second)
3. BLUE screen (1 second)
4. WHITE screen (1 second)

If the display stays blank:
- Check all connections are secure
- Verify VCC is getting 3.3V
- Confirm your display is ST7789 compatible
- Check backlight is connected and powered

## Troubleshooting

If the display doesn't work:
1. **Backlight not lit**: Check VCC and BLK connections to 3V3
2. **Backlight lit but no image**: Verify data pins (GPIO4, GPIO15, GPIO16)
3. **Display shows garbage**: May need different resolution (try 240x320)
4. **Nothing works**: Double-check display controller type (might be SSD1306, SH1106, etc.)
