#include "Recording.hpp"

#include <Arduino.h>
#include <Tof10120.hpp>
#include <TimeHelpers.hpp>

Recording_t::Recording_t()
    : distance_value{&TOF10120.get_value()}
{
}

void Recording_t::start()
{
    Serial.println("=== Recording Start ===");
    recording_running = true;

    recording_start = millis();
    distance_value.clear();
    begin_sample();
}

void Recording_t::update()
{
    if (!recording_running)
        return;

    if (distance_value.new_value_available())
    {
        if (distance_value.is_valid())
        {
            sample_count++;
            sample_sum += distance_value.get();
        }
    }

    if (event_is_over(sample_start + FILTER_PERIOD_MS))
    {
        finish_sample();
        begin_sample();
    }
}

void Recording_t::finish()
{
    recording_running = false;
    Serial.println("=== Recording End ===");
}

void Recording_t::begin_sample()
{
    sample_sum = 0;
    sample_count = 0;
    sample_start = millis();
}

void Recording_t::finish_sample()
{
    if (sample_count > 0)
    {
        store_sample(
            ((millis() + sample_start) / 2.0f - recording_start) / 1000.0f,
            sample_sum / float(sample_count));
    }
}

void Recording_t::store_sample(float time, float value)
{
    Serial.print(time);
    Serial.print(",");
    Serial.println(value);
}

Recording_t Recording{};
