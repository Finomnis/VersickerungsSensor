#include "TextHelper.hpp"

namespace TextHelper
{
    void drawText(Adafruit_SSD1306 &display,
                  const char *text,
                  int pos_x, int pos_y,
                  HorizontalAlign align_h, VerticalAlign align_v,
                  int *rendered_width, int *rendered_height)
    {
        int16_t start_x, start_y;
        uint16_t width, height;
        display.getTextBounds(text, 0, 0, &start_x, &start_y, &width, &height);

        int absolute_top{0};
        int absolute_left{0};

        switch (align_h)
        {
        case HorizontalAlign::H_LEFT:
            absolute_left = pos_x;
            break;
        case HorizontalAlign::H_CENTER:
            absolute_left = pos_x - width / 2;
            break;
        case HorizontalAlign::H_RIGHT:
            absolute_left = pos_x - width + 1;
            break;
        }
        switch (align_v)
        {
        case VerticalAlign::V_TOP:
            absolute_top = pos_y;
            break;
        case VerticalAlign::V_CENTER:
            absolute_top = pos_y - height / 2;
            break;
        case VerticalAlign::V_BOTTOM:
            absolute_top = pos_y - height + 1;
            break;
        }

        int cursor_x = absolute_left - start_x;
        int cursor_y = absolute_top - start_y;

        display.setCursor(cursor_x, cursor_y);
        display.print(text);

        if (rendered_height != nullptr)
            *rendered_height = height;
        if (rendered_width != nullptr)
            *rendered_width = width;
    }
}
