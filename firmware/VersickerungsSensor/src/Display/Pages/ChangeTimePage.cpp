#include "ChangeTimePage.hpp"

#include "../../utils/TextHelper/Adafruit_SSD1306.hpp"

#include <Fonts/FreeSansOblique9pt7b.h>

namespace Pages
{
    ChangeTimePage::ChangeTimePage()
        : header{"Zeit/Datum setzen"}
    {
        add_child(header);
    }

    void ChangeTimePage::set_highlight(uint32_t start, uint32_t end)
    {
        highlight_start = start;
        highlight_end = end;
        highlight_changed = true;

        reset_blink_state(false);
    }

    bool ChangeTimePage::check_dependencies_changed()
    {
        bool blink_state_changed = blink_state().new_value_available();
        bool date_time_changed = formatted_datetime().new_value_available();

        return blink_state_changed || date_time_changed || highlight_changed;
    }

    void ChangeTimePage::render(Adafruit_SSD1306 &display)
    {
        highlight_changed = false;

        if (!formatted_datetime().is_valid())
        {
            display.setFont(&FreeSansOblique9pt7b);
            TextHelper::drawText(display, "Clock Error",
                                 display.width() / 2,
                                 display.height() - 1,
                                 TextHelper::H_CENTER,
                                 TextHelper::V_BOTTOM);
            return;
        }

        constexpr size_t STRINGBUFFER_SIZE = 19;
        char part1[STRINGBUFFER_SIZE];
        char part2[STRINGBUFFER_SIZE];
        char part3[STRINGBUFFER_SIZE];

        memset(part1, 0, sizeof(part1));
        memset(part2, 0, sizeof(part2));
        memset(part3, 0, sizeof(part3));

        const char *time = formatted_datetime().get().str;

        strncpy(part1, time, highlight_start);
        strncpy(part2, time + highlight_start, highlight_end - highlight_start);
        strncpy(part3, time + highlight_end, sizeof(part3));

        display.setFont(&FreeSansOblique9pt7b);
        TextHelper::setCursor(display, time,
                              display.width() / 2,
                              display.height() - 1,
                              TextHelper::H_CENTER,
                              TextHelper::V_BOTTOM);

        display.print(part1);
        if (!blink_state().get())
        {
            display.setTextColor(SSD1306_BLACK);
        }
        display.print(part2);
        display.setTextColor(SSD1306_WHITE);
        display.print(part3);
    }
}
