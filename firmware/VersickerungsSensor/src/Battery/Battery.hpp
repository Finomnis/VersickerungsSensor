#pragma once

#include "../utils/ValueWatcher.hpp"
#include "../utils/NoMoveNoCopy.hpp"

enum BatteryFillState
{
    BATTERY_CRITICAL,
    BATTERY_1,
    BATTERY_2,
    BATTERY_3,
    BATTERY_4,
    BATTERY_5,
    BATTERY_6,
    BATTERY_FULL,
};

class Battery_t : NoMoveNoCopy
{
public:
    static constexpr float BATTERY_LEVEL_FULL = 4.2f;
    static constexpr float BATTERY_LEVEL_EMPTY = 3.6f;
    static constexpr uint32_t SAMPLE_PERIOD_MS = 2;
    static constexpr uint32_t PUBLISH_PERIOD_MS = 500;
    static constexpr float HYSTERESIS_THRESHOLD = 0.05;

public:
    Battery_t();

    void init();
    void update();

    Value<float> const &get_battery_voltage_value() { return battery_voltage_value; }
    Value<BatteryFillState> const &get_battery_state_value() { return battery_state_value; }

private:
    Value<float> battery_voltage_value;
    Value<BatteryFillState> battery_state_value;

    uint32_t next_sample_time;
    uint32_t next_publish_time;
    double value_sum;
    uint32_t value_count;
};

extern Battery_t Battery;
