#include "Header.hpp"

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
        return false;
    }

    void Header::render(Adafruit_SSD1306 &display)
    {
    }
}
