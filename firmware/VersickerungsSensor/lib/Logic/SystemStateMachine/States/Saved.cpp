#include "Saved.hpp"

#include <Arduino.h>
#include <TimeHelpers.hpp>

#include "Idle.hpp"

namespace SystemStateMachine::States
{
    void Saved::entry()
    {
        Serial.println("State: Saved");
        exitTime = millis() + 1000;
    }

    void Saved::update_state()
    {
        if (event_is_over(exitTime))
        {
            transit<Idle>();
        }
    }
};
