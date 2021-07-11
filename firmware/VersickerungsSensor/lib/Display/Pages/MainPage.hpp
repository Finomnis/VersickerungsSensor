#pragma once

#include <Adafruit_SSD1306.h>

void show_mainpage(Adafruit_SSD1306 &display,
                   const char *time,
                   bool recording,
                   bool bluetooth,
                   bool usb,
                   bool blink);
void show_mainpage(Adafruit_SSD1306 &display,
                   const char *time,
                   uint16_t distance_value,
                   bool recording,
                   bool bluetooth,
                   bool usb,
                   bool blink);

void show_mainpage_text(Adafruit_SSD1306 &display,
                        const char *time,
                        const char *text,
                        bool recording,
                        bool bluetooth,
                        bool usb,
                        bool blink);
