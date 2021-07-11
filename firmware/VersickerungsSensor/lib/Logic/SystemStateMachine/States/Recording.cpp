#include "Recording.hpp"

#include <Arduino.h>
#include <Display_128x32.hpp>
#include <Recording.hpp>

#include "Saved.hpp"

namespace SystemStateMachine::States
{
    void Recording::entry()
    {
        Serial.println("State: Recording");

        reset_blink_state();
        update_display();

        ::Recording.start();
    }

    void Recording::exit()
    {
        ::Recording.finish();
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
        changed |= formatted_time().new_value_available();

        if (changed)
        {
            update_display();
        }

        ::Recording.update();
    }

    void Recording::update_display()
    {
        if (filtered_distance().is_valid())
        {
            Display_128x32.show_mainpage(
                formatted_time().get().str,
                std::lround(filtered_distance().get()),
                true,
                true, //TODO
                true, //TODO
                blink_state().get());
        }
        else
        {
            Display_128x32.show_mainpage(
                formatted_time().get().str,
                true,
                true, //TODO
                true, //TODO
                blink_state().get());
        }
    }
}
