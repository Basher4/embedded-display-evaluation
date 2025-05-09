#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <GxEPD2_BW.h>
#include <Fonts/FreeMono24pt7b.h>

constexpr int DISPLAY_RESET = 20;
constexpr int DISPLAY_SPI_DIN = 19;
constexpr int DISPLAY_SPI_SCK = 18;
constexpr int DISPLAY_SPI_CS = 17;
constexpr int DISPLAY_DC = 15;
constexpr int DISPLAY_BUSY = 14;

GxEPD2_420 epd(DISPLAY_SPI_CS, DISPLAY_DC, DISPLAY_RESET, DISPLAY_BUSY);
GxEPD2_BW<GxEPD2_420, 300> display(epd); // Whole display comfortably fits into SRAM.

void setup() {
    Serial.begin(9600);
    Serial.println("Drawing to the screen");

    display.init(115200, true, 2, false);
    display.setFont(&FreeMono24pt7b);
    display.setTextColor(GxEPD_BLACK);

    display.setFullWindow();
    display.setCursor(10, 10);
    display.print("Hello, world!");
    display.nextPage();
}

void loop() {
    // put your main code here, to run repeatedly:
}
