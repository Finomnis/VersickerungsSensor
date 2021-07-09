#include "MainPage.hpp"

#include "Header.hpp"
#include <Fonts/FreeSansOblique12pt7b.h>

constexpr size_t STRINGBUFFER_SIZE = 10;
char stringBuffer[STRINGBUFFER_SIZE];

void show_mainpage(Adafruit_SSD1306 &display,
                   uint16_t distance_value,
                   bool recording,
                   bool bluetooth,
                   bool usb,
                   bool blink)
{
    display.clearDisplay();

    draw_header(display, recording, bluetooth, usb, blink);

    if (distance_value > 9999)
    {
        distance_value = 9999;
    }

    if (0 <= snprintf(stringBuffer, STRINGBUFFER_SIZE, "%d mm", distance_value))
    {
        display.setFont(&FreeSansOblique12pt7b);
        TextHelper::drawText(display, stringBuffer,
                             display.width() / 2, display.height() - 1,
                             TextHelper::H_CENTER,
                             TextHelper::V_BOTTOM);
    }

    display.display();
}
