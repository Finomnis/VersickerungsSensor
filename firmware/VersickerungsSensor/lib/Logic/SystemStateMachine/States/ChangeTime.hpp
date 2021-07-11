#pragma once

#include "../SystemState.hpp"

#include "Mixins/BlinkStateMixin.hpp"
#include "Mixins/DateTimeMixin.hpp"

namespace SystemStateMachine::States
{
    class ChangeTime
        : public SystemState,
          protected Mixins::BlinkStateMixin,
          protected Mixins::FormattedDateTimeMixin,
          protected Mixins::DateTimeMixin
    {
        void entry() override;

        void react(PressedButtonA const &e) override;
        void react(PressedButtonC const &e) override;

        void update_state() override;
        void update_display();
    };
}
