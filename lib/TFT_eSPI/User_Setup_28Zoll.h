

// ##################################################################################
// TFT_eSPI User_Setup.h
// TFT 2.8
// ##################################################################################


#define ST7735_DRIVER      // Define additional parameters below for this display


 #define TFT_WIDTH  240 // ST7789 240 x 320
 #define TFT_HEIGHT 320 // ST7789 240 x 320

 #define ST7735_REDTAB

// For ESP32 Dev board (only tested with ILI9341 display)
// The hardware SPI can be mapped to any pins

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   5  // Chip select control pin
#define TFT_DC   4  // Data Command control pin
#define TFT_RST  14 // Reset pin (could connect to RST pin)


#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts
#define SMOOTH_FONT
#define SPI_FREQUENCY  27000000 // Actually sets it to 26.67MHz = 80/3
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY  2500000

// ######################## END ##########################################################
