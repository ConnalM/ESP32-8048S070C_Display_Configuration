#include <Arduino.h>
#include <Arduino_GFX_Library.h>

// Pin definitions for ESP32-8048S070C
#define TFT_DE 41
#define TFT_VSYNC 40
#define TFT_HSYNC 39
#define TFT_PCLK 42
#define TFT_R0 14
#define TFT_R1 21
#define TFT_R2 47
#define TFT_R3 48
#define TFT_R4 45
#define TFT_G0 9
#define TFT_G1 46
#define TFT_G2 3
#define TFT_G3 8
#define TFT_G4 16
#define TFT_G5 1
#define TFT_B0 15
#define TFT_B1 7
#define TFT_B2 6
#define TFT_B3 5
#define TFT_B4 4
#define TFT_BL 2

// Screen dimensions
#define screenWidth 800
#define screenHeight 480

// Create the RGB panel with the correct timing parameters
Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
  TFT_DE, TFT_VSYNC, TFT_HSYNC, TFT_PCLK,
  TFT_R0, TFT_R1, TFT_R2, TFT_R3, TFT_R4,
  TFT_G0, TFT_G1, TFT_G2, TFT_G3, TFT_G4, TFT_G5,
  TFT_B0, TFT_B1, TFT_B2, TFT_B3, TFT_B4,
  0 /* hsync_polarity */, 210 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
  0 /* vsync_polarity */, 22 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */,
  1 /* pclk_active_neg */, 16000000 /* prefer_speed */
);

// Create the GFX instance
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
  screenWidth, screenHeight, bus, 0, true, NULL
);

void setup()
{
  Serial.begin(115200);
  
  // Initialize the display
  gfx->begin();
  
  // Turn on the backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // Clear the screen
  gfx->fillScreen(BLACK);
  
  // Draw a test pattern
  int barWidth = screenWidth / 8;
  uint16_t colors[8] = {RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN, WHITE, ORANGE};
  
  for (int i = 0; i < 8; i++) {
    int x = i * barWidth;
    gfx->fillRect(x, 0, barWidth, screenHeight, colors[i]);
    
    // Draw position text
    gfx->setTextColor(BLACK);
    gfx->setTextSize(3);
    gfx->setCursor(x + 10, screenHeight / 2);
    gfx->print(x);
  }
}

void loop()
{
  delay(1000);
}
