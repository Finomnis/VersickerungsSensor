#include "Idle.hpp"

#include <Arduino.h>
#include <Display_128x32.hpp>

#include "Recording.hpp"
#include "ChangeTime.hpp"

namespace SystemStateMachine::States
{
    void Idle::entry()
    {
        Serial.println("State: Idle");

        update_display();
    }

    void Idle::react(PressedButtonA const &e)
    {
        transit<Recording>();
    };
    void Idle::react(PressedButtonC const &e)
    {
        transit<ChangeTime>();
    };

    void Idle::update_state()
    {
        bool changed = false;

        changed |= filtered_distance().new_value_available();

        if (changed)
        {
            update_display();
        }
    }

    void Idle::update_display()
    {
        if (filtered_distance().is_valid())
        {
            Display_128x32.show_mainpage(
                formatted_time().get().str,
                std::lround(filtered_distance().get()),
                false,
                true, //TODO
                true, //TODO
                false);
        }
        else
        {
            Display_128x32.show_mainpage(
                formatted_time().get().str,
                false,
                true, //TODO
                true, //TODO
                false);
        }
    }
};
