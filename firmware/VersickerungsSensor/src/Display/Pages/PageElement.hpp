#pragma once

#include "../../utils/NoMoveNoCopy.hpp"

#include <Adafruit_SSD1306.h>

namespace Pages
{
    class PageElement : NoMoveNoCopy
    {
    public:
        void redraw_if_necessary(Adafruit_SSD1306 &display);
        void redraw(Adafruit_SSD1306 &display);

    protected:
        virtual bool check_dependencies() = 0;
        virtual void render(Adafruit_SSD1306 &display) = 0;

    private:
        bool recursive_check_dependencies();
        void recursive_render(Adafruit_SSD1306 &display);

        PageElement *first_child{nullptr};
        PageElement *next_sibling{nullptr};
    };
}
