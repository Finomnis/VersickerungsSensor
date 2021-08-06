#include "BatteryIcon.hpp"

#include "Assets/Icons.hpp"

namespace Pages::Elements
{
    bool BatteryIcon::check_dependencies_changed()
    {
        bool battery_changed = battery_state().new_value_available();

        bool blink_changed = false;
        if (battery_state().is_valid() && battery_state().get() == BATTERY_CRITICAL)
        {
            blink_changed = blink_state().new_value_available();
        }

        return battery_changed || blink_changed;
    }

    void BatteryIcon::render(Adafruit_SSD1306 &display)
    {
        if (!battery_state().is_valid())
        {
            return;
        }

        if (battery_state().get() == BATTERY_CRITICAL)
        {
            if (blink_state().get())
            {
                draw_battery_icon(display, display.width() - 5, 0, 0);
            }
        }
        else
        {
            draw_battery_icon(display, display.width() - 5, 0, int(battery_state().get()) - 1);
        }
    }
}
