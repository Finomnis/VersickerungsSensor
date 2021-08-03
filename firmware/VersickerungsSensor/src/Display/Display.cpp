#include "Display.hpp"

Display_t::Display_t()
{
}

void Display_t::init()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.display();
}

void Display_t::update()
{
    if (page != nullptr)
    {
        page->redraw_if_necessary(display);
    }
}

void Display_t::set_page(Pages::PageElement *new_page)
{
    page = new_page;
    if (page != nullptr)
    {
        page->redraw(display);
    }
}

Display_t Display{};
