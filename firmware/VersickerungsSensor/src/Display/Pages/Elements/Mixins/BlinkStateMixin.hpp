#pragma once

#include "../../../../utils/ValueWatcher.hpp"

namespace Pages::Elements::Mixins
{
    class BlinkStateMixin
    {
    protected:
        BlinkStateMixin();
        ValueWatcher<bool> &blink_state();

    public:
        void reset_blink_state(bool target_state = true);

    private:
        static void update_blink_state();

    private:
        ValueWatcher<bool> blink_state_valuewatcher;
        static Value<bool> blink_state_value;
        static uint32_t blink_state_start;
        static constexpr uint32_t blink_rate_ms{500};
    };
}
