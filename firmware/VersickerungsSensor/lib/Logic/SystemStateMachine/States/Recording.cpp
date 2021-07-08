#include "Recording.hpp"

#include <Arduino.h>

#include "Saved.hpp"

namespace SystemStateMachine::States
{
    void Recording::entry()
    {
        Serial.println("State: Recording");
    }

    void Recording::react(PressedButtonA const &e)
    {
        transit<Saved>();
    };
};
