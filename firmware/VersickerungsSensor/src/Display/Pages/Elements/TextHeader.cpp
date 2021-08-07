#include "TextHeader.hpp"

#include "../../../utils/TextHelper/Adafruit_SSD1306.hpp"

namespace Pages::Elements
{
    TextHeader::TextHeader(const char *text)
        : text{text}
    {
        add_child(battery_icon);
        add_child(usb_icon);
    }

    bool TextHeader::check_dependencies_changed()
    {
        bool datetime_changed = formatted_datetime().new_value_available();

        return datetime_changed;
    }

    void TextHeader::render(Adafruit_SSD1306 &display)
    {
        display.setFont(nullptr);
        TextHelper::drawText(display, text,
                             0, 0,
                             TextHelper::H_LEFT,
                             TextHelper::V_TOP);
    }
}
