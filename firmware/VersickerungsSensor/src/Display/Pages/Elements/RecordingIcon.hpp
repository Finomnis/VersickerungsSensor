#pragma once

#include "../PageElement.hpp"

#include "Mixins/BlinkStateMixin.hpp"

namespace Pages::Elements
{
    class RecordingIcon : public PageElement,
                          private Mixins::BlinkStateMixin
    {
    public:
        RecordingIcon(bool recording);

    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;

        const bool recording;
    };
}
