#pragma once

#include "../SystemState.hpp"

#include "Mixins/DateTimeMixin.hpp"

#include <Arduino.h>

namespace SystemStateMachine::States
{
    class Saved
        : public SystemState,
          protected Mixins::DateTimeMixin
    {
        void entry() override;
        void update_state() override;
        void update_display();

    private:
        uint32_t exitTime;
    };
}
