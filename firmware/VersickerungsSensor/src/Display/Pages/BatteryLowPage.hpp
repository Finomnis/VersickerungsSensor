#pragma once

#include "PageElement.hpp"

namespace Pages
{
    class BatteryLowPage : public PageElement
    {
        bool check_dependencies_changed() override { return false; };
        void render(Adafruit_SSD1306 &display) override;
    };
}
