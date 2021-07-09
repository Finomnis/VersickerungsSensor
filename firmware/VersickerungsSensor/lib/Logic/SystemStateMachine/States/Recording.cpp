#include "Recording.hpp"

#include <Arduino.h>
#include <Display_128x32.hpp>

#include "Saved.hpp"

namespace SystemStateMachine::States
{
    void Recording::entry()
    {
        Serial.println("State: Recording");

        reset_blink_state();
        update_display();
    }

    void Recording::react(PressedButtonA const &e)
    {
        transit<Saved>();
    };

    void Recording::update_state()
    {
        bool changed = false;

        changed |= filtered_distance().new_value_available();
        changed |= blink_state().new_value_available();

        if (changed)
        {
            update_display();
        }
    }

    void Recording::update_display()
    {
        Display_128x32.show_mainpage(
            std::lround(filtered_distance().get()),
            true,
            true, //TODO
            true, //TODO
            blink_state().get());
    }
}
