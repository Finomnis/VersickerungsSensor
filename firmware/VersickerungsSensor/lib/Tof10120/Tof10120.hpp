#pragma once

#include <Arduino.h>
#include <ValueWatcher.hpp>

class TOF10120
{
public:
    TOF10120(uint8_t i2c_addr);
    void update();

    ValueWatcher<uint16_t> create_watcher();

private:
    void update_request();
    void update_response();

private:
    uint8_t i2c_addr;
    bool requestPending = false;
    uint32_t responseExpected = 0;
    Value<uint16_t> value;
};
