#include "Display_128x32.hpp"

#include <Wire.h>

#include "Pages/MainPage.hpp"

Display_128x32_t::Display_128x32_t()
    : display{DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire}
{
}

void Display_128x32_t::init()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.display();
}

void Display_128x32_t::show_mainpage(
    bool recording,
    bool bluetooth,
    bool usb,
    bool blink)
{
    ::show_mainpage(display, recording, bluetooth,
                    usb, blink);
}

void Display_128x32_t::show_mainpage(
    uint16_t distance_value,
    bool recording,
    bool bluetooth,
    bool usb,
    bool blink)
{
    ::show_mainpage(display, distance_value, recording, bluetooth,
                    usb, blink);
}

void Display_128x32_t::show_mainpage_text(
    const char *text,
    bool recording,
    bool bluetooth,
    bool usb,
    bool blink)
{
    ::show_mainpage_text(display, text, recording, bluetooth,
                         usb, blink);
}

Display_128x32_t Display_128x32;
