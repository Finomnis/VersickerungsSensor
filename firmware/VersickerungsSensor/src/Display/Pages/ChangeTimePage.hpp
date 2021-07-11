#pragma once

#include <Adafruit_SSD1306.h>

void show_changetimepage(Adafruit_SSD1306 &display,
                         const char *time,
                         uint32_t highlight_start,
                         uint32_t highlight_end,
                         bool bluetooth,
                         bool usb,
                         bool blink);
