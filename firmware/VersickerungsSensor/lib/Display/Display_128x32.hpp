#pragma once

#include <Adafruit_SSD1306.h>

class Display_128x32_t
{
    static constexpr size_t DISPLAY_WIDTH = 128;
    static constexpr size_t DISPLAY_HEIGHT = 32;

public:
    Display_128x32_t();
    void init();

private:
    Adafruit_SSD1306 display;
};

extern Display_128x32_t Display_128x32;
