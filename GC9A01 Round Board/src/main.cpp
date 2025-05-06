#include <Arduino.h>
#include <SPI.h>
// #include <SoftwareSPI.h>
#include <Arduino_GFX_Library.h>

// constexpr int DISPLAY_SPI_SCK = 14;
// constexpr int DISPLAY_SPI_SDA = 15;
constexpr int DISPLAY_SPI_CS = 20;
constexpr int DISPLAY_DC = 17;
constexpr int DISPLAY_RESET = 16;

// SoftwareSPI sw_spi(DISPLAY_SPI_SCK, 1, DISPLAY_SPI_SDA);
Arduino_HWSPI bus(DISPLAY_DC, DISPLAY_SPI_CS);
Arduino_GC9A01 display(&bus, DISPLAY_RESET, 2, true);

void setup() {
  Serial.begin(9600);

  // set SPI pins
  // SPI.setSCK(DISPLAY_SPI_SCK);
  // SPI.setTX(DISPLAY_SPI_SDA);
  // SPI.setCS(DISPLAY_SPI_CS);

  Serial.println("Drawing to the screen");

  display.begin();
  display.fillScreen(0x512B);
  display.drawRect(50, 50, 50, 50, 0xFFFF);
  display.setTextColor(RGB565_RED);
  display.setCursor(100, 100);
  display.println("Hello world");
}

void loop() {
  // put your main code here, to run repeatedly:
}
