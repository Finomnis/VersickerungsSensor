#include "RecordingIcon.hpp"

#include "Assets/Icons.hpp"

namespace Pages::Elements
{
    RecordingIcon::RecordingIcon(bool recording)
        : recording{recording}
    {
    }

    bool RecordingIcon::check_dependencies_changed()
    {
        bool blink_state_changed = false;

        if (recording)
        {
            blink_state_changed = blink_state().new_value_available();
        }

        return blink_state_changed;
    }

    void RecordingIcon::render(Adafruit_SSD1306 &display)
    {
        if (recording)
        {
            if (blink_state().get())
            {
                draw_record_icon(display, display.width() - 34, 0);
            }
        }
        else
        {
            draw_pause_icon(display, display.width() - 34, 0);
        }
    }

    void RecordingIcon::on_activate(Adafruit_SSD1306 &display)
    {
        reset_blink_state();
    }
}
