# Testing displays

Recently I acquired a collection of various displays. I have a few projects in mind for them, but for that I want to evaluate them. How much work it is to interface with them, what are their strengths and weaknesses.

# Setup

- Raspberry Pi Pico (RP2040)
- Arduino for its libraries
- PlatformIO

## Flash Pico firmware through PlatformIO

There was one quirk with flashing built firmware on the Pi Pico. Since I am using Windows 11, I needed to download [Zadig](https://zadig.akeo.ie/) and override the USB driver to WinUSB.

In `platformio.ini` I specified `upload_protocol = picotool` and then things worked.
