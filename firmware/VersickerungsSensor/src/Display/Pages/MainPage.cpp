#include "MainPage.hpp"

#include "../../utils/TextHelper/Adafruit_SSD1306.hpp"

#include <Fonts/FreeSansOblique12pt7b.h>

namespace Pages
{
    MainPage::MainPage(bool recording)
        : header{recording}
    {
        add_child(header);
    }

    bool MainPage::check_dependencies_changed()
    {
        return filtered_distance().new_value_available();
    }

    void MainPage::render(Adafruit_SSD1306 &display)
    {
        const auto draw_text = [&display](const char *txt)
        {
            display.setFont(&FreeSansOblique12pt7b);
            TextHelper::drawText(display, txt,
                                 display.width() / 2, display.height() - 1,
                                 TextHelper::H_CENTER,
                                 TextHelper::V_BOTTOM);
        };

        if (filtered_distance().is_valid())
        {
            char stringBuffer[128];
            uint16_t distance_value = std::lround(filtered_distance().get());

            if (distance_value > 9999)
            {
                distance_value = 9999;
            }

            if (0 <= snprintf(stringBuffer, sizeof(stringBuffer), "%d mm", distance_value))
            {
                draw_text(stringBuffer);
            }
            else
            {
                draw_text("Error");
            }
        }
        else
        {
            draw_text("-- mm");
        }
    }
}
