#include "Display_128x32.hpp"

#include <Wire.h>

Display_128x32_t::Display_128x32_t()
    : display{DISPLAY_WIDTH, DISPLAY_HEIGHT, &Wire}
{
}

void Display_128x32_t::init()
{
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
    display.display();
}

Display_128x32_t Display_128x32;
