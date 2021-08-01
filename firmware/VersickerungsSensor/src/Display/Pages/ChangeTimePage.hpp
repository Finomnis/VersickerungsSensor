#pragma once

#include <Adafruit_SSD1306.h>

#include "../../Battery/Battery.hpp"

void show_changetimepage(Adafruit_SSD1306 &display,
                         const char *time,
                         uint32_t highlight_start,
                         uint32_t highlight_end,
                         bool bluetooth,
                         bool usb,
                         bool blink,
                         BatteryFillState battery_state);
