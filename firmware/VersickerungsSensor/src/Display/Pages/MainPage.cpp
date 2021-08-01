#include "MainPage.hpp"

#include "Header.hpp"
#include <Fonts/FreeSansOblique9pt7b.h>
#include <Fonts/FreeSansOblique12pt7b.h>

namespace
{
    constexpr size_t STRINGBUFFER_SIZE = 10;
    char stringBuffer[STRINGBUFFER_SIZE];
}

void show_mainpage(Adafruit_SSD1306 &display,
                   const char *time,
                   bool recording,
                   bool bluetooth,
                   bool usb,
                   bool blink,
                   BatteryFillState battery_state)
{
    show_mainpage_text(display, time, "-- mm", recording, bluetooth, usb, blink, battery_state);
}

void show_mainpage(Adafruit_SSD1306 &display,
                   const char *time,
                   uint16_t distance_value,
                   bool recording,
                   bool bluetooth,
                   bool usb,
                   bool blink,
                   BatteryFillState battery_state)
{
    if (distance_value > 9999)
    {
        distance_value = 9999;
    }

    if (0 <= snprintf(stringBuffer, STRINGBUFFER_SIZE, "%d mm", distance_value))
    {
        show_mainpage_text(display, time, stringBuffer, recording, bluetooth, usb, blink, battery_state);
    }
    else
    {
        show_mainpage_text(display, time, "Error", recording, bluetooth, usb, blink, battery_state);
    }
}

void show_mainpage_text(Adafruit_SSD1306 &display,
                        const char *time,
                        const char *text,
                        bool recording,
                        bool bluetooth,
                        bool usb,
                        bool blink,
                        BatteryFillState battery_state,
                        bool small_text)
{
    display.clearDisplay();

    draw_header(display, time, recording, bluetooth, usb, blink, battery_state);

    if (small_text)
    {
        display.setFont(&FreeSansOblique9pt7b);
    }
    else
    {
        display.setFont(&FreeSansOblique12pt7b);
    }
    TextHelper::drawText(display, text,
                         display.width() / 2, display.height() - 1,
                         TextHelper::H_CENTER,
                         TextHelper::V_BOTTOM);

    display.display();
}
