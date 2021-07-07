#pragma once

#include <Arduino.h>

class TOF10120
{
public:
    TOF10120(uint8_t i2c_addr);
    void update();

private:
    void update_request();
    void update_response();

private:
    uint8_t i2c_addr;
    bool requestPending = false;
    unsigned long responseExpected = (unsigned long)-1;
};
