#include "Icons.hpp"

namespace
{
    // Data generated with https://javl.github.io/image2cpp/

    // 'USB', 5x9px
    const unsigned char bitmap_USB[] PROGMEM = {
        0x20, 0x28, 0xa8, 0xb0, 0x60, 0x20, 0x70, 0x70, 0x70};

    // 'Bluetooth', 5x9px
    const unsigned char bitmap_Bluetooth[] PROGMEM = {
        0x20, 0x30, 0xa8, 0x50, 0x20, 0x50, 0xa8, 0x30, 0x20};

    // 'Record', 9x9px
    const unsigned char bitmap_Record[] PROGMEM = {
        0x1c, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0xff, 0x80, 0xff, 0x80, 0xff, 0x80, 0x7f, 0x00, 0x7f, 0x00,
        0x1c, 0x00};

    // 'Pause', 9x9px
    const unsigned char bitmap_Pause[] PROGMEM = {
        0x77, 0x00, 0x77, 0x00, 0x77, 0x00, 0x77, 0x00, 0x77, 0x00, 0x77, 0x00, 0x77, 0x00, 0x77, 0x00,
        0x77, 0x00};
}

void draw_usb_icon(Adafruit_SSD1306 &display, int16_t x, int16_t y)
{
    display.drawBitmap(x, y, bitmap_USB, 5, 9, SSD1306_WHITE);
}

void draw_bluetooth_icon(Adafruit_SSD1306 &display, int16_t x, int16_t y)
{
    display.drawBitmap(x, y, bitmap_Bluetooth, 5, 9, SSD1306_WHITE);
}

void draw_pause_icon(Adafruit_SSD1306 &display, int16_t x, int16_t y)
{
    display.drawBitmap(x, y, bitmap_Pause, 9, 9, SSD1306_WHITE);
}

void draw_record_icon(Adafruit_SSD1306 &display, int16_t x, int16_t y)
{
    display.drawBitmap(x, y, bitmap_Record, 9, 9, SSD1306_WHITE);
}
