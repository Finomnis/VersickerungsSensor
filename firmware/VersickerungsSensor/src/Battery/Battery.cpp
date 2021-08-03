#include "Battery.hpp"

#include "../utils/TimeHelpers.hpp"

namespace
{
    float voltage_to_fillstate_float(float voltage)
    {
        float amount = (voltage - Battery_t::BATTERY_LEVEL_EMPTY) /
                       (Battery_t::BATTERY_LEVEL_FULL - Battery_t::BATTERY_LEVEL_EMPTY);

        constexpr int divs = int(BATTERY_FULL) - 1;

        return amount * divs + 1;
    }
}

Battery_t::Battery_t()
    : battery_voltage_value{0.0f, false},
      battery_state_value{BATTERY_FULL, false},
      next_sample_time{millis()},
      next_publish_time{millis() + PUBLISH_PERIOD_MS},
      value_sum{0.0f},
      value_count{0}
{
}

void Battery_t::init()
{
    pinMode(PIN_VBAT, INPUT);
}

void Battery_t::update()
{
    if (event_is_over(next_sample_time))
    {
        next_sample_time = millis() + SAMPLE_PERIOD_MS;

        float battery_voltage = analogRead(PIN_VBAT);
        battery_voltage *= 2;
        battery_voltage *= 3.6;
        battery_voltage /= 1024;

        value_sum += battery_voltage;
        value_count += 1;
    }

    if (event_is_over(next_publish_time))
    {
        next_publish_time = millis() + PUBLISH_PERIOD_MS;

        if (value_count == 0)
        {
            // Set voltage to invalid
            battery_voltage_value.update(0, false);
        }
        else
        {
            float smoothed_value = float(value_sum / value_count);

            float new_state_float = voltage_to_fillstate_float(smoothed_value);
            BatteryFillState new_state = BatteryFillState(round(new_state_float));

            // Update voltage
            float rounded_voltage = roundf(smoothed_value * 100) / 100;
            if (!battery_voltage_value.is_valid() || battery_voltage_value.get() != rounded_voltage)
            {
                battery_voltage_value.update(rounded_voltage);
            }

            if (new_state_float < 1.0 - HYSTERESIS_THRESHOLD)
            {
                new_state = BATTERY_CRITICAL;
                new_state_float = 0.0;
            }

            // Update fill state
            if (!battery_state_value.is_valid())
            {
                battery_state_value.update(new_state);
            }
            else
            {
                float old_state_float = battery_state_value.get();
                if (old_state_float < 0.5f)
                {
                    old_state_float = 0.5f;
                }

                if (abs(new_state_float - old_state_float) >= (0.5 + HYSTERESIS_THRESHOLD))
                {
                    battery_state_value.update(new_state);
                }
            }
        }

        value_sum = 0;
        value_count = 0;
    }
}

Battery_t Battery{};
