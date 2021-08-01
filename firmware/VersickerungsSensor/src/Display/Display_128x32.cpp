#include "Display_128x32.hpp"

#include <Wire.h>

#include "Pages/MainPage.hpp"
#include "Pages/ChangeTimePage.hpp"

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
    const char *time,
    bool recording,
    bool bluetooth,
    bool usb,
    bool blink,
    BatteryFillState battery_state)
{
    ::show_mainpage(display, time, recording, bluetooth,
                    usb, blink, battery_state);
}

void Display_128x32_t::show_mainpage(
    const char *time,
    uint16_t distance_value,
    bool recording,
    bool bluetooth,
    bool usb,
    bool blink,
    BatteryFillState battery_state)
{
    ::show_mainpage(display, time, distance_value, recording, bluetooth,
                    usb, blink, battery_state);
}

void Display_128x32_t::show_mainpage_text(
    const char *time,
    const char *text,
    bool recording,
    bool bluetooth,
    bool usb,
    bool blink,
    BatteryFillState battery_state,
    bool small_text)
{
    ::show_mainpage_text(display, time, text, recording, bluetooth,
                         usb, blink, battery_state, small_text);
}

void Display_128x32_t::show_changetimepage(const char *time,
                                           uint32_t highlight_start,
                                           uint32_t highlight_end,
                                           bool bluetooth,
                                           bool usb,
                                           bool blink,
                                           BatteryFillState battery_state)
{
    ::show_changetimepage(display, time, highlight_start, highlight_end,
                          bluetooth, usb, blink, battery_state);
}

Display_128x32_t Display_128x32;
