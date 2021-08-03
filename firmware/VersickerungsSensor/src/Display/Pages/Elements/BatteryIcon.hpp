#pragma once

#include "../PageElement.hpp"

#include "Mixins/BatteryStateMixin.hpp"
#include "Mixins/BlinkStateMixin.hpp"

namespace Pages
{
    namespace Elements
    {
        class BatteryIcon : public PageElement,
                            private Mixins::BatteryStateMixin,
                            private Mixins::BlinkStateMixin
        {
        protected:
            bool check_dependencies() override;
            void render(Adafruit_SSD1306 &display) override;
        };
    }
}
