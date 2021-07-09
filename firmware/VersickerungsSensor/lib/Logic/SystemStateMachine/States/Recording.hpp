#pragma once

#include "../SystemState.hpp"

#include "Mixins/FilteredDistanceMixin.hpp"
#include "Mixins/BlinkStateMixin.hpp"

namespace SystemStateMachine::States
{
    class Recording
        : public SystemState,
          protected Mixins::FilteredDistanceMixin,
          protected Mixins::BlinkStateMixin
    {
        void entry() override;
        void exit() override;

        void react(PressedButtonA const &e) override;

        void update_state() override;
        void update_display();
    };
}
