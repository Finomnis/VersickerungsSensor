#include "BlinkStateMixin.hpp"

namespace SystemStateMachine::States::Mixins
{
    BlinkStateMixin::BlinkStateMixin()
        : blink_state_valuewatcher{&blink_state_value}
    {
        reset_blink_state();
    }

    ValueWatcher<bool> &BlinkStateMixin::blink_state()
    {
        update_blink_state();
        return blink_state_valuewatcher;
    }

    void BlinkStateMixin::reset_blink_state()
    {
        blink_state_start = millis();
        update_blink_state();
    }

    void BlinkStateMixin::update_blink_state()
    {
        uint32_t phase = (millis() - blink_state_start) % blink_rate_ms;
        bool blink_value = phase < blink_rate_ms / 2;
        if (blink_state_value.get() != blink_value)
        {
            blink_state_value.update(blink_value);
        }
    }

    Value<bool> BlinkStateMixin::blink_state_value{true};
    uint32_t BlinkStateMixin::blink_state_start{0};
}
