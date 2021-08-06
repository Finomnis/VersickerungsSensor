#include "Header.hpp"

#include "../../../utils/TextHelper/Adafruit_SSD1306.hpp"

namespace Pages::Elements
{
    Header::Header(bool recording)
        : recording_icon{recording}
    {
        add_child(battery_icon);
        add_child(usb_icon);
        add_child(recording_icon);
    }

    bool Header::check_dependencies_changed()
    {
        bool datetime_changed = formatted_datetime().new_value_available();

        return datetime_changed;
    }

    void Header::render(Adafruit_SSD1306 &display)
    {
        display.setFont(nullptr);
        TextHelper::drawText(display, formatted_datetime().get().str,
                             0, 0,
                             TextHelper::H_LEFT,
                             TextHelper::V_TOP);
    }
}
