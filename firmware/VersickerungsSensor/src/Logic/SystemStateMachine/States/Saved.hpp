#pragma once

#include "../SystemState.hpp"

#include "Mixins/DateTimeMixin.hpp"
#include "Mixins/UsbConnectedMixin.hpp"
#include "Mixins/BatteryStateMixin.hpp"
#include "Mixins/BlinkStateMixin.hpp"

#include <Arduino.h>

namespace SystemStateMachine::States
{
    class Saved
        : public SystemState,
          protected Mixins::FormattedDateTimeMixin,
          protected Mixins::BlinkStateMixin,
          protected Mixins::UsbConnectedMixin,
          protected Mixins::BatteryStateMixin
    {
        void entry() override;
        void update_state() override;
        void update_display();

    private:
        uint32_t exitTime;
    };
}
