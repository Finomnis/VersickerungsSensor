#include "ChangeTimePage.hpp"

#include "Header.hpp"
#include <Fonts/FreeSansOblique12pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>

namespace
{
    constexpr size_t STRINGBUFFER_SIZE = 19;
    char part1[STRINGBUFFER_SIZE];
    char part2[STRINGBUFFER_SIZE];
    char part3[STRINGBUFFER_SIZE];
}

void show_changetimepage(Adafruit_SSD1306 &display,
                         const char *time,
                         uint32_t highlight_start,
                         uint32_t highlight_end,
                         bool bluetooth,
                         bool usb,
                         bool blink,
                         BatteryFillState battery_state)
{
    display.clearDisplay();

    draw_header(display, "Zeit/Datum setzen", true, bluetooth, usb, blink, battery_state);

    memset(part1, 0, sizeof(part1));
    memset(part2, 0, sizeof(part2));
    memset(part3, 0, sizeof(part3));

    strncpy(part1, time, highlight_start);
    strncpy(part2, time + highlight_start, highlight_end - highlight_start);
    strncpy(part3, time + highlight_end, sizeof(part3));

    display.setFont(&FreeSansOblique9pt7b);
    TextHelper::setCursor(display, time,
                          display.width() / 2,
                          display.height() - 1,
                          TextHelper::H_CENTER,
                          TextHelper::V_BOTTOM);

    display.print(part1);
    if (!blink)
    {
        display.setTextColor(SSD1306_BLACK);
    }
    display.print(part2);
    display.setTextColor(SSD1306_WHITE);
    display.print(part3);

    display.display();
}
