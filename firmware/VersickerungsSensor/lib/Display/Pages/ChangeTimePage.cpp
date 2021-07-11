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
                         bool blink)
{
    display.clearDisplay();

    draw_header(display, "Zeit/Datum setzen", true, bluetooth, usb, false);

    memset(part1, 0, sizeof(part1));
    memset(part2, 0, sizeof(part2));
    memset(part3, 0, sizeof(part3));

    strncpy(part1, time, highlight_start);
    strncpy(part2, time + highlight_start, highlight_end - highlight_start);
    strncpy(part3, time + highlight_end, sizeof(part3));

    uint16_t part1Width;
    uint16_t part2Width;
    uint16_t part3Width;

    display.setFont(&FreeSansOblique9pt7b);
    TextHelper::getTextDimensions(display, part1, &part1Width);
    display.setFont(&FreeSansOblique12pt7b);
    TextHelper::getTextDimensions(display, part2, &part2Width);
    display.setFont(&FreeSansOblique9pt7b);
    TextHelper::getTextDimensions(display, part3, &part3Width);

    // Add spaces
    if ((part1Width > 0 && part2Width > 0) ||
        (part1Width > 0 && part3Width > 0))
    {
        part1Width += 3;
    }
    if (part2Width > 0 && part3Width > 0)
    {
        part2Width += 1;
    }

    uint16_t totalWidth = part1Width + part2Width + part3Width;

    int16_t totalLeft = TextHelper::getLeft(display.width() / 2, totalWidth,
                                            TextHelper::H_CENTER);

    display.setFont(&FreeSansOblique9pt7b);
    TextHelper::drawText(display, part1,
                         totalLeft,
                         display.height() - 1,
                         TextHelper::H_LEFT,
                         TextHelper::V_BOTTOM);

    if (blink)
    {
        display.setFont(&FreeSansOblique12pt7b);
        TextHelper::drawText(display, part2,
                             totalLeft + part1Width,
                             display.height() - 1,
                             TextHelper::H_LEFT,
                             TextHelper::V_BOTTOM);
    }

    display.setFont(&FreeSansOblique9pt7b);
    TextHelper::drawText(display, part3,
                         totalLeft + part1Width + part2Width,
                         display.height() - 1,
                         TextHelper::H_LEFT,
                         TextHelper::V_BOTTOM);

    display.display();
}
