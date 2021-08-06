#include "UsbIcon.hpp"

#include "Assets/Icons.hpp"

namespace Pages::Elements
{
    bool UsbIcon::check_dependencies_changed()
    {
        bool usb_changed = usb_connected().new_value_available();

        return usb_changed;
    }

    void UsbIcon::render(Adafruit_SSD1306 &display)
    {
        if (!usb_connected().is_valid())
        {
            return;
        }

        if (usb_connected().get())
        {
            draw_usb_icon(display, display.width() - 12, 0);
        }
    }
}
