#include "SavedPage.hpp"

#include "../../utils/TextHelper/Adafruit_SSD1306.hpp"

#include <Fonts/FreeSansOblique9pt7b.h>

namespace Pages
{
    SavedPage::SavedPage()
        : header{false}
    {
        add_child(header);
    }

    bool SavedPage::check_dependencies_changed()
    {
        return false;
    }

    void SavedPage::render(Adafruit_SSD1306 &display)
    {
        display.setFont(&FreeSansOblique9pt7b);
        TextHelper::drawText(display, "Gespeichert",
                             display.width() / 2, display.height() - 1,
                             TextHelper::H_CENTER,
                             TextHelper::V_BOTTOM);
    }
}
