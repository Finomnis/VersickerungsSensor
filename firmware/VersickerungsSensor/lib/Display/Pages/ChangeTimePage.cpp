#include "ChangeTimePage.hpp"

#include "Header.hpp"
#include <Fonts/FreeSansOblique12pt7b.h>
#include <Fonts/FreeSansOblique9pt7b.h>

namespace
{
    constexpr size_t STRINGBUFFER_SIZE = 19;
    char stringBuffer[STRINGBUFFER_SIZE];
}

void show_changetimepage(Adafruit_SSD1306 &display,
                         const char *time,
                         uint32_t highlight_start,
                         uint32_t highlight_end,
                         bool bluetooth,
                         bool usb,
                         bool blink)
{
    display.clearDisplay();

    draw_header(display, "Adjust date/time", true, bluetooth, usb, false);

    memset(stringBuffer, 0, sizeof(stringBuffer));

    if (blink)
    {
        display.setFont(&FreeSansOblique9pt7b);
        TextHelper::drawText(display, time,
                             display.width() / 2, display.height() - 1,
                             TextHelper::H_CENTER,
                             TextHelper::V_BOTTOM);
    }

    display.display();
}
