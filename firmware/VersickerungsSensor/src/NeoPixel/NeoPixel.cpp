#include "NeoPixel.hpp"

NeoPixel_t::NeoPixel_t()
    : pixel{1, PIN_NEOPIXEL}
{
}

void NeoPixel_t::init()
{
    pixel.begin();
    set_color(0, 0, 0);
}

void NeoPixel_t::set_color(uint8_t r, uint8_t g, uint8_t b)
{
    pixel.clear();
    pixel.setPixelColor(0, pixel.Color(r, g, b));
    pixel.show();
}

NeoPixel_t NeoPixel{};
