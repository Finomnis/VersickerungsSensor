#pragma once

#include <Arduino.h>
#include <TimeHelpers.hpp>

template <uint32_t PIN>
class Button
{
private:
    static constexpr uint32_t DEBOUNCE_TIME_MS = 50;

public:
    void init()
    {
        pinMode(PIN, INPUT_PULLUP);
        attachInterrupt(digitalPinToInterrupt(PIN),
                        Button<PIN>::on_press, FALLING);
    }

    bool was_triggered()
    {
        // Take value and clear
        noInterrupts();
        bool result = pressed;
        pressed = false;
        interrupts();

        return result;
    }

    static Button &get()
    {
        static Button button{};
        return button;
    };

private:
    static void
    on_press()
    {
        uint32_t now = millis();
        if (event_is_over(get().debounce_end, now))
        {
            get().pressed = true;
            get().debounce_end = now + DEBOUNCE_TIME_MS;
        }
    }

private:
    bool pressed;
    uint32_t debounce_end;
};
