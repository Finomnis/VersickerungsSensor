#pragma once

#include "../PageElement.hpp"

#include "BatteryIcon.hpp"
#include "UsbIcon.hpp"

namespace Pages::Elements
{
    class Header : public PageElement
    {
    public:
        Header();

    protected:
        bool check_dependencies_changed() override { return false; };
        void render(Adafruit_SSD1306 &display) override{};

    private:
        BatteryIcon battery_icon{};
        UsbIcon usb_icon{};
    };
}
