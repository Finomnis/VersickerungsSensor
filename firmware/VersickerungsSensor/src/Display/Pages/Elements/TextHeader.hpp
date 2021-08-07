#pragma once

#include "../PageElement.hpp"

#include "BatteryIcon.hpp"
#include "UsbIcon.hpp"

#include "Mixins/DateTimeMixin.hpp"

namespace Pages::Elements
{
    class TextHeader : public PageElement,
                       private Mixins::FormattedDateTimeMixin
    {
    public:
        TextHeader(const char *text);

    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;

    private:
        BatteryIcon battery_icon{};
        UsbIcon usb_icon{};
        const char *text;
    };
}
