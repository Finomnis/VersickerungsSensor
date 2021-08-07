#pragma once

#include "../PageElement.hpp"

#include "Mixins/BatteryStateMixin.hpp"
#include "Mixins/BlinkStateMixin.hpp"

namespace Pages::Elements
{
    class BatteryIcon : public PageElement,
                        private Mixins::BatteryStateMixin,
                        private Mixins::BlinkStateMixin
    {
    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;
    };
}
