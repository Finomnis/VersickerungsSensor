#pragma once

#include "../PageElement.hpp"

#include "Mixins/UsbConnectedMixin.hpp"

namespace Pages::Elements
{
    class UsbIcon : public PageElement,
                    private Mixins::UsbConnectedMixin
    {
    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;
    };
}
