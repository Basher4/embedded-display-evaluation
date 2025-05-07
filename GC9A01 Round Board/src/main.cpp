#include <Arduino.h>
#include <SPI.h>
#include <Arduino_GFX_Library.h>

// constexpr int DISPLAY_SPI_SCK = 18;
constexpr int DISPLAY_SPI_SDA = 7;
constexpr int DISPLAY_SPI_CS = 20;
constexpr int DISPLAY_DC = 17;
constexpr int DISPLAY_RESET = 16;

// SoftwareSPI sw_spi(DISPLAY_SPI_SCK, 1, DISPLAY_SPI_SDA);
Arduino_HWSPI bus(DISPLAY_DC, DISPLAY_SPI_CS);
Arduino_GC9A01 display(&bus, DISPLAY_RESET, 2, true);

void setup() {
    Serial.begin(9600);

    // set SPI pin
    SPI.setMOSI(DISPLAY_SPI_SDA);

    Serial.println("Drawing to the screen");

    display.begin();
    display.fillScreen(0x512B);
    display.setTextColor(RGB565_RED);

    display.startWrite();
    display.writeFillRect(50, 50, 50, 50, 0b01110'110100'00111);
    display.setCursor(75, 75);
    display.println("Hello world");
    display.endWrite();
}

void loop() {
    // put your main code here, to run repeatedly:
}
