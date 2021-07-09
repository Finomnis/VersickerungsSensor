#pragma once

#include <ValueWatcher.hpp>

class Recording_t
{
public:
    Recording_t();

    void start();
    void update();
    void finish();

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

    static constexpr uint32_t FILTER_PERIOD_MS = 5000;

    ValueWatcher<uint16_t> distance_value;
};

extern Recording_t Recording;
