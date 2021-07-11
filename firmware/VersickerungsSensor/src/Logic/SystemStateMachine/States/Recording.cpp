#include "Recording.hpp"

#include <Arduino.h>

#include "../../../Display/Display_128x32.hpp"

#include "../../../Recording/Recording.hpp"

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
        changed |= formatted_datetime().new_value_available();
        changed |= usb_connected().new_value_available();

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
                formatted_datetime().get().str,
                std::lround(filtered_distance().get()),
                true,
                false, //TODO
                usb_connected().get(),
                blink_state().get());
        }
        else
        {
            Display_128x32.show_mainpage(
                formatted_datetime().get().str,
                true,
                false, //TODO
                usb_connected().get(),
                blink_state().get());
        }
    }
}
