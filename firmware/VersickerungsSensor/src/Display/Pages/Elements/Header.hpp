#pragma once

#include "../PageElement.hpp"

#include "BatteryIcon.hpp"
#include "UsbIcon.hpp"
#include "RecordingIcon.hpp"

#include "Mixins/DateTimeMixin.hpp"

namespace Pages::Elements
{
    class Header : public PageElement,
                   private Mixins::FormattedDateTimeMixin
    {
    public:
        Header(bool recording);

    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;

    private:
        BatteryIcon battery_icon{};
        UsbIcon usb_icon{};
        RecordingIcon recording_icon;
    };
}
