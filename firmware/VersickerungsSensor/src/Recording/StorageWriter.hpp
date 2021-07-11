#pragma once

#include "../RTC/RTC.hpp"

class StorageWriter
{
public:
    void init();

    void start(DateTime start_time);
    void write_sample(float sample_time, float sample_value);
    void finish();

private:
    char folder_name[12] = {0};
    char file_name[16] = {0};
};
