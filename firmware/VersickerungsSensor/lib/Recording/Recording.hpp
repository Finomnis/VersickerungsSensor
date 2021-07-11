#pragma once

#include <ValueWatcher.hpp>
#include <RTC.hpp>

#include "StorageWriter.hpp"

class Recording_t
{
public:
    Recording_t();

    void init();

    bool start();
    bool update();
    bool finish();

private:
    void store_sample(float time, float value);
    void begin_sample();
    void finish_sample();

private:
    uint32_t sample_sum{0};
    uint32_t sample_count{0};
    uint32_t sample_start{0};
    uint32_t recording_start{0};
    bool recording_running{false};

    static constexpr uint32_t FILTER_PERIOD_S = 5;

    ValueWatcher<uint16_t> distance_value;
    ValueWatcher<DateTime> time_value;

    StorageWriter storage_writer{};
};

extern Recording_t Recording;
