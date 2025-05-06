#include <Arduino.h>
#include <Adafruit_SSD1306.h>

// I2C Setup for the dispaly
constexpr int OLED_WIDTH = 128;
constexpr int OLED_HEIGHT = 32;
constexpr int OLED_I2C_SDA = 14;
constexpr int OLED_I2C_SCK = 15;
constexpr int OLED_I2C_ADDR = 0x3C;
constexpr int OLED_RESET = -1; // Reset pin is not exposed on the display.

TwoWire pico_i2c(OLED_I2C_SDA, OLED_I2C_SCK);
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &pico_i2c, OLED_RESET,
                         3'300'000UL /* I2C Transfer Frequency */,
                         100'000UL /* I2C Idle Frequency */
                        );

uint32_t *fb = nullptr;
constexpr size_t FB_SIZE = OLED_WIDTH * OLED_HEIGHT / 8 / sizeof(fb[0]);

uint32_t last_ts = 0;
uint32_t pattern = 0xFF00;

char buf[22];

void setup()
{
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    fb = (uint32_t *)display.getBuffer();
    last_ts = micros();
}

void loop()
{
    uint32_t cur_ts = micros();

    sprintf(buf, "%0.2f FPS", 1000000.0f / (cur_ts - last_ts));

    display.clearDisplay();
    display.setCursor(0, 0);
    display.write(buf);

    display.setCursor(0, 10);
    display.write("Code");
    display.setCursor(0, 18);
    display.write("Review");
    display.setCursor(0, 26);
    display.write("Done");

    display.drawLine(0, 32, 128, 32, 1);
    display.drawLine(64, 0, 64, 64, 1);

    display.display();

    last_ts = cur_ts;
}