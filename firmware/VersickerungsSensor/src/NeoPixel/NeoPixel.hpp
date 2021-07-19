#pragma once

#include <Adafruit_NeoPixel.h>

class NeoPixel_t
{
public:
    NeoPixel_t();
    void init();

    void set_color(uint8_t r, uint8_t g, uint8_t b);

private:
    Adafruit_NeoPixel pixel;
};

extern NeoPixel_t NeoPixel;
