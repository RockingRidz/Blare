#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_SCLK 0
#define TFT_MOSI 1
#define TFT_RST  2
#define TFT_DC   3
#define TFT_CS   4
#define TFT_BL   5

class MyST7789 : public Adafruit_ST7789 {
public:
  MyST7789(int8_t cs, int8_t dc, int8_t mosi, int8_t sclk, int8_t rst)
    : Adafruit_ST7789(cs, dc, mosi, sclk, rst) {}
  void setOffsets(uint8_t col, uint8_t row) {
    _colstart = _colstart2 = col;
    _rowstart = _rowstart2 = row;
  }
};

MyST7789 tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup() {
  Serial.begin(115200);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, LOW);

  tft.init(76, 284);
  tft.setOffsets(82, 18);
  tft.invertDisplay(false);
  tft.setRotation(1);
  
  Serial.println("TFT Initialized!");

  tft.fillScreen(ST77XX_BLACK);

  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(6);
  tft.setCursor(0, 0);
  tft.print(42); 
}

void loop() {
}
