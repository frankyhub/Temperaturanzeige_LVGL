/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
  Funktion: TFT 2.8 Temperaturanzeige

**************************************************************************************************
  Version: 18.10.2024
**************************************************************************************************
  Board: ESP32 DEV Module
**************************************************************************************************
  Libraries:
  https://github.com/espressif/arduino-esp32/tree/master/libraries
  C:\Users\User\Documents\Arduino
  D:\gittemp\Arduino II\A156_Wetterdaten_V3
**************************************************************************************************
  C++ Arduino IDE V2.3.3
**************************************************************************************************
  Einstellungen:
  https://dl.espressif.com/dl/package_esp32_index.json
  http://dan.drown.org/stm32duino/package_STM32duino_index.json
  http://arduino.esp8266.com/stable/package_esp8266com_index.json
**************************************************************************************************
  TFT Bibliotheken:

  Adafruit_ILI9341 by Adafruit Version 1.6.00
  Adafruit_GFX by Adafruit Version 1.11.9
  XPT2046_Touchscreen by Paul Stoffregen Version 1.4.0
  Touchevent by Gerald-Lechner Version 1.3.0

*************************************************************************************
Verdrahtung:
TFT 	  ESP32
T_IRQ	  GPIO 36
T_OUT	  GPIO 39
T_DIN	  GPIO 32
T_CS	  GPIO 33
T_CLK	  GPIO 25
SDO(MISO)	GPIO 12
LED	    GPIO 21
SCK	    GPIO 14
SDI(MOSI)	GPIO 13
D/C	    GPIO 2
RESET	  EN/RESET
CS	    GPIO 15
GND	    GND
VCC	    5V 

**********************************************************************
//User_Setup.h
//Temperaturanzeige TFT2.8" ESP32 DEV Module

#define USER_SETUP_INFO "User_Setup"
#define ILI9341_2_DRIVER     // Alternative ILI9341 driver, see https://github.com/Bodmer/TFT_eSPI/issues/1172
#define TFT_WIDTH  240 // ST7789 240 x 240 and 240 x 320
#define TFT_HEIGHT 320 // ST7789 240 x 320

#define TFT_BL   21            // LED back-light control pin
#define TFT_BACKLIGHT_ON HIGH  // Level to turn ON back-light (HIGH or LOW)
#define TFT_MISO 12
#define TFT_MOSI 13
#define TFT_SCLK 14
#define TFT_CS   15  // Chip select control pin
#define TFT_DC    2  // Data Command control pin
#define TFT_RST  -1  // Set TFT_RST to -1 if display RESET is connected to ESP32 board RST
#define TOUCH_CS 33     // Chip select pin (T_CS) of touch screen

#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8  // Font 8. Large 75 pixel font needs ~3256 bytes in FLASH, only characters 1234567890:-.
//#define LOAD_FONT8N // Font 8. Alternative to Font 8 above, slightly narrower, so 3 digits fit a 160 pixel TFT
#define LOAD_GFXFF  // FreeFonts. Include access to the 48 Adafruit_GFX free fonts FF1 to FF48 and custom fonts

#define SPI_FREQUENCY  55000000 // STM32 SPI1 only (SPI2 maximum is 27MHz)
#define SPI_READ_FREQUENCY  20000000
#define SPI_TOUCH_FREQUENCY  2500000
#define USE_HSPI_PORT
*****************************************************************************/
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// GPIO DS18B20
const int oneWireBus = 27;     

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

// FAHRENHEIT = 0
#define TEMP_CELSIUS 1    

#if TEMP_CELSIUS
  #define TEMP_ARC_MIN -20
  #define TEMP_ARC_MAX 40
#else
  #define TEMP_ARC_MIN -4
  #define TEMP_ARC_MAX 104
#endif

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

void log_print(lv_log_level_t level, const char * buf) {
  LV_UNUSED(level);
  Serial.println(buf);
  Serial.flush();
}

lv_obj_t * arc;

static void set_temp(void * text_label_temp_value, int32_t v) {
  sensors.requestTemperatures();
  #if TEMP_CELSIUS
    float ds18b20_temp = sensors.getTempCByIndex(0);
    if(ds18b20_temp <= 10.0) {
      lv_obj_set_style_text_color((lv_obj_t*) text_label_temp_value, lv_palette_main(LV_PALETTE_BLUE), 0);
    }
    else if (ds18b20_temp > 10.0 && ds18b20_temp <= 29.0) {
      lv_obj_set_style_text_color((lv_obj_t*) text_label_temp_value, lv_palette_main(LV_PALETTE_GREEN), 0);
    }
    else {
      lv_obj_set_style_text_color((lv_obj_t*) text_label_temp_value, lv_palette_main(LV_PALETTE_RED), 0);
    }
    const char degree_symbol[] = "\u00B0C";
  #else
    float ds18b20_temp = sensors.getTempFByIndex(0);
    if(ds18b20_temp <= 50.0) {
      lv_obj_set_style_text_color((lv_obj_t*) text_label_temp_value, lv_palette_main(LV_PALETTE_BLUE), 0);
    }
    else if (ds18b20_temp > 50.0 && ds18b20_temp <= 84.2) {
      lv_obj_set_style_text_color((lv_obj_t*) text_label_temp_value, lv_palette_main(LV_PALETTE_GREEN), 0);
    }
    else {
      lv_obj_set_style_text_color((lv_obj_t*) text_label_temp_value, lv_palette_main(LV_PALETTE_RED), 0);
    }
    const char degree_symbol[] = "\u00B0F";
  #endif

  lv_arc_set_value(arc, map(int(ds18b20_temp), TEMP_ARC_MIN, TEMP_ARC_MAX, 0, 100));

  String ds18b20_temp_text = String(ds18b20_temp) + degree_symbol;
  lv_label_set_text((lv_obj_t*) text_label_temp_value, ds18b20_temp_text.c_str());
  Serial.print("Temperature: ");
  Serial.println(ds18b20_temp_text);
}

void lv_create_main_gui(void) {
  // Create an Arc
  arc = lv_arc_create(lv_screen_active());
  lv_obj_set_size(arc, 210, 210);
  lv_arc_set_rotation(arc, 135);
  lv_arc_set_bg_angles(arc, 0, 270);
  lv_obj_set_style_arc_color(arc, lv_color_hex(0x666666), LV_PART_INDICATOR);
  lv_obj_set_style_bg_color(arc, lv_color_hex(0x333333), LV_PART_KNOB);
  lv_obj_align(arc, LV_ALIGN_CENTER, 0, 10);
  lv_obj_t * text_label_temp_value = lv_label_create(lv_screen_active());
  lv_label_set_text(text_label_temp_value, "--.--");
  lv_obj_align(text_label_temp_value, LV_ALIGN_CENTER, 0, 10);
  static lv_style_t style_temp;
  lv_style_init(&style_temp);
  lv_style_set_text_font(&style_temp, &lv_font_montserrat_32);
  lv_obj_add_style(text_label_temp_value, &style_temp, 0);
  lv_anim_t a_temp;
  lv_anim_init(&a_temp);
  lv_anim_set_exec_cb(&a_temp, set_temp);
  lv_anim_set_duration(&a_temp, 1000000);
  lv_anim_set_playback_duration(&a_temp, 1000000);
  lv_anim_set_var(&a_temp, text_label_temp_value);
  lv_anim_set_values(&a_temp, 0, 100);
  lv_anim_set_repeat_count(&a_temp, LV_ANIM_REPEAT_INFINITE);
  lv_anim_start(&a_temp);
}

void setup() {
  String LVGL_Arduino = String("LVGL Library Version: ") + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
  Serial.begin(115200);
  Serial.println(LVGL_Arduino);
  sensors.begin();
  lv_init();
  lv_log_register_print_cb(log_print);

  lv_display_t * disp;
  disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
  lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);
  lv_create_main_gui();
}

void loop() {
  lv_task_handler();  
  lv_tick_inc(5);     
  delay(5);       
}
