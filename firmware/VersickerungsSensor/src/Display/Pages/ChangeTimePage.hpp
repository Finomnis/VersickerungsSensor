#pragma once

#include "PageElement.hpp"

#include "Elements/TextHeader.hpp"
#include "Elements/Mixins/DateTimeMixin.hpp"
#include "Elements/Mixins/BlinkStateMixin.hpp"

namespace Pages
{
    class ChangeTimePage : public PageElement,
                           private Elements::Mixins::FormattedDateTimeMixin,
                           private Elements::Mixins::BlinkStateMixin
    {
    public:
        ChangeTimePage();
        void set_highlight(uint32_t start, uint32_t end);

    protected:
        bool check_dependencies_changed() override;
        void render(Adafruit_SSD1306 &display) override;

    private:
        Elements::TextHeader header;
        uint32_t highlight_start{0};
        uint32_t highlight_end{0};
        bool highlight_changed{false};
    };
}
