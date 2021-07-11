#include "Saved.hpp"

#include <Arduino.h>
#include <TimeHelpers.hpp>
#include <Display_128x32.hpp>

#include "Idle.hpp"

namespace SystemStateMachine::States
{
    void Saved::entry()
    {
        Serial.println("State: Saved");
        exitTime = millis() + 2000;

        update_display();
    }

    void Saved::update_state()
    {
        bool changed = false;

        if (changed)
        {
            update_display();
        }

        if (event_is_over(exitTime))
        {
            transit<Idle>();
        }
    }

    void Saved::update_display()
    {
        Display_128x32.show_mainpage_text(
            formatted_time().get().str,
            "Saved",
            false,
            true, //TODO
            true, //TODO
            false);
    }
};
