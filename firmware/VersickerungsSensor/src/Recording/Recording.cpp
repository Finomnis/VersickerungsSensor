#include "Recording.hpp"

#include <Arduino.h>
#include "../Tof10120/Tof10120.hpp"
#include "../utils/TimeHelpers.hpp"

Recording_t::Recording_t()
    : distance_value{&TOF10120.get_value()},
      time_value{&RTC.get_time_value()}
{
}

void Recording_t::init()
{
    storage_writer.init();
}

bool Recording_t::start()
{
    Serial.println("=== Recording Start ===");
    if (!time_value.is_valid())
    {
        Serial.println("Error: Unable to record. Time is not valid.");
        return false;
    }

    recording_running = true;

    recording_start = time_value.get().unixtime();
    distance_value.clear();

    storage_writer.start(time_value.get());

    begin_sample();

    return true;
}

bool Recording_t::update()
{
    if (!recording_running)
        return false;

    if (!time_value.is_valid())
    {
        Serial.println("Error: time is not valid.");
        return false;
    }

    if (distance_value.new_value_available())
    {
        if (distance_value.is_valid())
        {
            sample_count++;
            sample_sum += distance_value.get();
        }
    }

    if (time_value.new_value_available() && time_value.get().unixtime() >= sample_start + FILTER_PERIOD_S)
    {
        finish_sample();
        begin_sample();
    }

    return true;
}

bool Recording_t::finish()
{
    if (!recording_running)
    {
        return false;
    }

    recording_running = false;
    Serial.println("=== Recording End ===");

    storage_writer.finish();

    return true;
}

void Recording_t::begin_sample()
{
    sample_sum = 0;
    sample_count = 0;
    sample_start = time_value.get().unixtime();
}

void Recording_t::finish_sample()
{
    if (sample_count > 0)
    {
        store_sample(
            sample_start - recording_start,
            sample_sum / float(sample_count));
    }
}

void Recording_t::store_sample(float time, float value)
{
    storage_writer.write_sample(time, value);
}

Recording_t Recording{};
