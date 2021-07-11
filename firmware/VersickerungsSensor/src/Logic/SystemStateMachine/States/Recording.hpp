#pragma once

#include "../SystemState.hpp"

#include "Mixins/FilteredDistanceMixin.hpp"
#include "Mixins/BlinkStateMixin.hpp"
#include "Mixins/DateTimeMixin.hpp"
#include "Mixins/UsbConnectedMixin.hpp"

namespace SystemStateMachine::States
{
    class Recording
        : public SystemState,
          protected Mixins::FilteredDistanceMixin,
          protected Mixins::BlinkStateMixin,
          protected Mixins::FormattedDateTimeMixin,
          protected Mixins::UsbConnectedMixin
    {
        void entry() override;
        void exit() override;

        void react(PressedButtonA const &e) override;

        void update_state() override;
        void update_display();
    };
}