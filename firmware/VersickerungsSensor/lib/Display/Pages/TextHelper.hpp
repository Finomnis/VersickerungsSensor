#pragma once

#include <Adafruit_SSD1306.h>

namespace TextHelper
{
    enum VerticalAlign
    {
        V_BOTTOM,
        V_CENTER,
        V_TOP
    };
    enum HorizontalAlign
    {
        H_LEFT,
        H_CENTER,
        H_RIGHT
    };

    int getLeft(int pos_x, int width, HorizontalAlign align_h);
    int getTop(int pos_y, int height, VerticalAlign align_v);
    void getTextDimensions(Adafruit_SSD1306 &display,
                           const char *text,
                           uint16_t *width,
                           uint16_t *height = nullptr);

    void drawText(Adafruit_SSD1306 &display,
                  const char *text,
                  int pos_x, int pos_y,
                  HorizontalAlign align_h, VerticalAlign align_v,
                  int *rendered_width = nullptr,
                  int *rendered_height = nullptr);
}
