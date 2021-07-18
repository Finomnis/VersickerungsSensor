#pragma once

#include <Adafruit_SSD1306.h>
#include "../../utils/TextHelper/Adafruit_SSD1306.hpp"
#include "Icons.hpp"

inline void draw_header(Adafruit_SSD1306 &display,
                        const char *time,
                        bool recording,
                        bool bluetooth,
                        bool usb,
                        bool blink)
{
    display.setFont(nullptr);
    TextHelper::drawText(display, time,
                         0, 0,
                         TextHelper::H_LEFT,
                         TextHelper::V_TOP);

    if (usb)
    {
        draw_usb_icon(display, display.width() - 5, 0);
    }

    if (bluetooth)
    {
        draw_bluetooth_icon(display, display.width() - 12, 0);
    }

    if (recording)
    {
        if (blink)
        {
            draw_record_icon(display, display.width() - 28, 0);
        }
    }
    else
    {
        draw_pause_icon(display, display.width() - 28, 0);
    }
}
