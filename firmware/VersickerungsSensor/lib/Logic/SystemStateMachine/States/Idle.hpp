#pragma once

#include "../SystemState.hpp"
#include "Mixins/FilteredDistanceMixin.hpp"
#include "Mixins/DateTimeMixin.hpp"

namespace SystemStateMachine::States
{
    class Idle
        : public SystemState,
          protected Mixins::FilteredDistanceMixin,
          protected Mixins::DateTimeMixin
    {
        void entry() override;
        void react(PressedButtonA const &e) override;
        void react(PressedButtonC const &e) override;
        void update_state() override;
        void update_display();
    };
}
