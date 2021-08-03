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

    // 'Battery_6', 5x9px
    const unsigned char bitmap_Battery_6[] PROGMEM = {
        0x70, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8};
    // 'Battery_5', 5x9px
    const unsigned char bitmap_Battery_5[] PROGMEM = {
        0x70, 0xd8, 0x88, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8};
    // 'Battery_4', 5x9px
    const unsigned char bitmap_Battery_4[] PROGMEM = {
        0x70, 0xd8, 0x88, 0x88, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8};
    // 'Battery_3', 5x9px
    const unsigned char bitmap_Battery_3[] PROGMEM = {
        0x70, 0xd8, 0x88, 0x88, 0x88, 0xf8, 0xf8, 0xf8, 0xf8};
    // 'Battery_2', 5x9px
    const unsigned char bitmap_Battery_2[] PROGMEM = {
        0x70, 0xd8, 0x88, 0x88, 0x88, 0x88, 0xf8, 0xf8, 0xf8};
    // 'Battery_1', 5x9px
    const unsigned char bitmap_Battery_1[] PROGMEM = {
        0x70, 0xd8, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf8, 0xf8};
    // 'Battery_0', 5x9px
    const unsigned char bitmap_Battery_0[] PROGMEM = {
        0x70, 0xd8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf8};

    // 'Battery', 5x9px, 7 images
    const unsigned char *bitmap_Battery[7] = {
        bitmap_Battery_0,
        bitmap_Battery_1,
        bitmap_Battery_2,
        bitmap_Battery_3,
        bitmap_Battery_4,
        bitmap_Battery_5,
        bitmap_Battery_6};
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

void draw_battery_icon(Adafruit_SSD1306 &display, int16_t x, int16_t y, uint8_t state)
{
    if (state > 6)
    {
        return;
    }

    display.drawBitmap(x, y, bitmap_Battery[state], 5, 9, SSD1306_WHITE);
}
