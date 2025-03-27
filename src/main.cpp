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
#define CUSTOM_TFT_BL 2  // Renamed to avoid conflict with ESP32-S3-Box definition

// Screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

// Store color constants in PROGMEM to save RAM
const PROGMEM uint16_t colorBars[] = {RED, GREEN, BLUE, YELLOW, MAGENTA, CYAN, WHITE, ORANGE};
const PROGMEM uint16_t circleColors[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

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
  SCREEN_WIDTH, SCREEN_HEIGHT, bus, 0, true,
  NULL, CUSTOM_TFT_BL  // Use our custom backlight pin
);

// Pattern counter
uint8_t currentPattern = 0;
unsigned long lastPatternChange = 0;
const uint16_t patternDuration = 5000; // 5 seconds per pattern

// Function prototypes
void drawColorBars();
void drawGradient();
void drawCheckerboard();
void drawConcentricCircles();
void drawPatternName(const char* name, uint16_t color);

void setup()
{
  Serial.begin(115200);
  delay(500); // Short delay to ensure serial is ready
  
  Serial.println("\n\n----- ESP32-8048S070C Display Test -----");
  Serial.println("Board: ESP32-8048S070C");
  Serial.println("Resolution: 800x480");
  Serial.println("Initializing display...");
  
  // Initialize the display
  unsigned long startTime = millis();
  gfx->begin();
  unsigned long initTime = millis() - startTime;
  Serial.print("Display initialized in ");
  Serial.print(initTime);
  Serial.println(" ms");
  
  // Turn on the backlight
  pinMode(CUSTOM_TFT_BL, OUTPUT);
  digitalWrite(CUSTOM_TFT_BL, HIGH);
  Serial.println("Backlight turned ON");

  // Clear the screen
  gfx->fillScreen(BLACK);
  Serial.println("Screen cleared");
  
  // Draw initial pattern
  Serial.println("Drawing initial pattern: Color Bars");
  drawColorBars();
  
  // Initialize pattern change timer
  lastPatternChange = millis();
  Serial.println("Setup complete, entering main loop");
}

void loop()
{
  // Check if it's time to change patterns
  if (millis() - lastPatternChange > patternDuration) {
    // Move to next pattern
    currentPattern = (currentPattern + 1) % 4;
    
    // Clear screen
    gfx->fillScreen(BLACK);
    
    // Draw the new pattern
    Serial.print("Changing to pattern ");
    Serial.print(currentPattern);
    Serial.print(": ");
    
    unsigned long startTime = millis();
    
    switch (currentPattern) {
      case 0:
        Serial.println("Color Bars");
        drawColorBars();
        break;
      case 1:
        Serial.println("Gradient");
        drawGradient();
        break;
      case 2:
        Serial.println("Checkerboard");
        drawCheckerboard();
        break;
      case 3:
        Serial.println("Concentric Circles");
        drawConcentricCircles();
        break;
    }
    
    unsigned long drawTime = millis() - startTime;
    Serial.print("Pattern drawn in ");
    Serial.print(drawTime);
    Serial.println(" ms");
    
    // Update timer
    lastPatternChange = millis();
  }
}

// Helper function to draw pattern name - reduces code duplication
void drawPatternName(const char* name, uint16_t color = WHITE) {
  gfx->setTextColor(color);
  gfx->setTextSize(2);
  gfx->setCursor(10, 10);
  gfx->print(name);
}

// Pattern 1: Color Bars
void drawColorBars() {
  Serial.println("Drawing color bars pattern");
  const uint16_t barWidth = SCREEN_WIDTH / 8;
  
  for (uint8_t i = 0; i < 8; i++) {
    const uint16_t x = i * barWidth;
    // Get color from PROGMEM
    const uint16_t color = pgm_read_word(&colorBars[i]);
    gfx->fillRect(x, 0, barWidth, SCREEN_HEIGHT, color);
    
    // Draw position text
    gfx->setTextColor(BLACK);
    gfx->setTextSize(3);
    gfx->setCursor(x + 10, SCREEN_HEIGHT / 2);
    gfx->print(x);
  }
  
  // Draw pattern name
  drawPatternName("Pattern 1: Color Bars");
  Serial.println("Color bars pattern complete");
}

// Pattern 2: Gradient - optimized to use fewer calculations
void drawGradient() {
  Serial.println("Drawing gradient pattern");
  // Pre-calculate values for better performance
  const uint16_t halfHeight = SCREEN_HEIGHT / 2;
  
  // Draw horizontal gradient (red to blue) with fewer calculations
  for (uint16_t x = 0; x < SCREEN_WIDTH; x++) {
    // Use bit shifting for faster calculation (multiply by 255 and divide by SCREEN_WIDTH)
    uint8_t r = ((SCREEN_WIDTH - x) * 255) / SCREEN_WIDTH;
    uint8_t b = (x * 255) / SCREEN_WIDTH;
    uint16_t color = gfx->color565(r, 0, b);
    
    gfx->drawFastVLine(x, 0, halfHeight, color);
  }
  
  // Draw vertical gradient (green to yellow) with fewer calculations
  for (uint16_t y = halfHeight; y < SCREEN_HEIGHT; y++) {
    // Use bit shifting for faster calculation
    uint8_t g = ((SCREEN_HEIGHT - y) * 255) / (SCREEN_HEIGHT - halfHeight);
    uint8_t r = ((y - halfHeight) * 255) / (SCREEN_HEIGHT - halfHeight);
    uint16_t color = gfx->color565(r, g, 0);
    
    gfx->drawFastHLine(0, y, SCREEN_WIDTH, color);
  }
  
  // Draw pattern name
  drawPatternName("Pattern 2: Gradient");
  Serial.println("Gradient pattern complete");
}

// Pattern 3: Checkerboard - optimized to reduce calculations
void drawCheckerboard() {
  Serial.println("Drawing checkerboard pattern");
  const uint8_t squareSize = 40;
  bool isWhite;
  
  // Pre-calculate row count and column count
  const uint8_t rows = (SCREEN_HEIGHT + squareSize - 1) / squareSize;
  const uint8_t cols = (SCREEN_WIDTH + squareSize - 1) / squareSize;
  
  // Draw checkerboard with fewer conditional checks
  for (uint8_t y = 0; y < rows; y++) {
    isWhite = y & 1; // Faster than y % 2
    
    for (uint8_t x = 0; x < cols; x++) {
      gfx->fillRect(x * squareSize, y * squareSize, 
                   squareSize, squareSize, 
                   isWhite ? WHITE : BLACK);
      isWhite = !isWhite;
    }
  }
  
  // Draw pattern name
  drawPatternName("Pattern 3: Checkerboard", RED);
  Serial.println("Checkerboard pattern complete");
}

// Pattern 4: Concentric Circles - optimized to reduce calculations
void drawConcentricCircles() {
  Serial.println("Drawing concentric circles pattern");
  const uint16_t centerX = SCREEN_WIDTH / 2;
  const uint16_t centerY = SCREEN_HEIGHT / 2;
  const uint16_t maxRadius = min(SCREEN_WIDTH, SCREEN_HEIGHT) / 2;
  const uint8_t step = 20; // Distance between circles
  
  // Draw from largest to smallest for better visual effect
  for (uint16_t r = maxRadius; r > 0; r -= step) {
    // Calculate color index with faster modulo (for powers of 2, use bitwise AND)
    const uint8_t colorIndex = ((maxRadius - r) / step) % 6;
    const uint16_t color = pgm_read_word(&circleColors[colorIndex]);
    gfx->fillCircle(centerX, centerY, r, color);
  }
  
  // Draw pattern name
  drawPatternName("Pattern 4: Concentric Circles");
  Serial.println("Concentric circles pattern complete");
}
