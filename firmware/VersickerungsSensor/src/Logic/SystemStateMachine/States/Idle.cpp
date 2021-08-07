#include "Idle.hpp"

#include <Arduino.h>

#include "../../../Display/Display.hpp"

#include "Recording.hpp"
#include "ChangeTime.hpp"

namespace SystemStateMachine::States
{
    void Idle::entry()
    {
        Serial.println("State: Idle");

        Display.set_page(&page);
    }

    void Idle::react(PressedButtonA const &e)
    {
        transit<Recording>();
    }
    void Idle::react(PressedButtonC const &e)
    {
        transit<ChangeTime>();
    }
};
