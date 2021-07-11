#include "ChangeTime.hpp"

#include <Arduino.h>
#include <Display_128x32.hpp>

#include "Idle.hpp"

namespace SystemStateMachine::States
{
    void ChangeTime::entry()
    {
        Serial.println("State: ChangeTime");

        reset_blink_state();
        update_display();
    }

    void ChangeTime::react(PressedButtonA const &e)
    {
        Serial.println("Adjust time");
    };

    void ChangeTime::react(PressedButtonC const &e)
    {
        transit<Idle>();
    };

    void ChangeTime::update_state()
    {
        bool changed = false;

        changed |= blink_state().new_value_available();
        changed |= formatted_time().new_value_available();

        if (changed)
        {
            update_display();
        }
    }

    void ChangeTime::update_display()
    {
        Display_128x32.show_changetimepage(
            formatted_time().get().str,
            3,
            4,
            true, //TODO
            true, //TODO
            blink_state().get());
    }
};
