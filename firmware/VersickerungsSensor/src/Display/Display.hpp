#pragma once

#include "../utils/NoMoveNoCopy.hpp"

#include "Pages/PageElement.hpp"

#include <Adafruit_SSD1306.h>

class Display_t : NoMoveNoCopy
{
    static constexpr size_t DISPLAY_WIDTH = 128;
    static constexpr size_t DISPLAY_HEIGHT = 32;

public:
    Display_t();

    void init();
    void update();
    void set_page(Pages::PageElement *new_page);

private:
    Adafruit_SSD1306 display;
    Pages::PageElement *page{nullptr};
};

extern Display_t Display;
