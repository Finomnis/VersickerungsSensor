#include "BatteryLowPage.hpp"

#include "../../utils/TextHelper/Adafruit_SSD1306.hpp"

namespace Pages
{
    void BatteryLowPage::render(Adafruit_SSD1306 &display)
    {
        display.setFont();
        TextHelper::drawText(display, "Batterie leer",
                             display.width() / 2, display.height() / 2,
                             TextHelper::H_CENTER,
                             TextHelper::V_CENTER);
    }
}
