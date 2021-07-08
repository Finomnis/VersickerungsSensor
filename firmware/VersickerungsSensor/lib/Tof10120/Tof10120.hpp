#pragma once

#include <Arduino.h>
#include <ValueWatcher.hpp>
#include <NoMoveNoCopy.hpp>

class TOF10120_inst
{
    NOMOVE_NOCOPY(TOF10120_inst);

public:
    TOF10120_inst(uint8_t i2c_addr);
    void update();

    const Value<uint16_t> &get_value() const;

private:
    void update_request();
    void update_response();

private:
    uint8_t i2c_addr;
    bool requestPending = false;
    uint32_t responseExpected = 0;
    Value<uint16_t> value;
};

extern TOF10120_inst TOF10120;
