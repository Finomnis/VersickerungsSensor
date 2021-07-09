#pragma once

#include "../SystemState.hpp"
#include "Mixins/FilteredDistanceMixin.hpp"

namespace SystemStateMachine::States
{
    class Idle
        : public SystemState,
          protected Mixins::FilteredDistanceMixin
    {
        void entry() override;
        void react(PressedButtonA const &e) override;
        void react(PressedButtonC const &e) override;
        void update_state() override;
        void update_display();
    };
}
