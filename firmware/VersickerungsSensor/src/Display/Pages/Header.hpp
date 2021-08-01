#pragma once

#include <Adafruit_SSD1306.h>
#include "../../utils/TextHelper/Adafruit_SSD1306.hpp"
#include "../../Battery/Battery.hpp"
#include "Icons.hpp"

inline void draw_header(Adafruit_SSD1306 &display,
                        const char *time,
                        bool recording,
                        bool bluetooth,
                        bool usb,
                        bool blink,
                        BatteryFillState battery_state)
{
    display.setFont(nullptr);
    TextHelper::drawText(display, time,
                         0, 0,
                         TextHelper::H_LEFT,
                         TextHelper::V_TOP);

    if (battery_state != BATTERY_CRITICAL || blink)
    {
        draw_battery_icon(display, display.width() - 5, 0, uint8_t(battery_state) - 1);
    }

    if (usb)
    {
        draw_usb_icon(display, display.width() - 12, 0);
    }

    if (bluetooth)
    {
        draw_bluetooth_icon(display, display.width() - 19, 0);
    }

    if (recording)
    {
        if (blink)
        {
            draw_record_icon(display, display.width() - 34, 0);
        }
    }
    else
    {
        draw_pause_icon(display, display.width() - 34, 0);
    }
}
