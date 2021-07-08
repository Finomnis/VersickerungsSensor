#include "ChangeTime.hpp"

#include <Arduino.h>
#include <TimeHelpers.hpp>

#include "Idle.hpp"

namespace SystemStateMachine::States
{
    void ChangeTime::entry()
    {
        Serial.println("State: ChangeTime");
    }

    void ChangeTime::react(PressedButtonA const &e)
    {
        Serial.println("Adjust time");
    };

    void ChangeTime::react(PressedButtonC const &e)
    {
        transit<Idle>();
    };
};
