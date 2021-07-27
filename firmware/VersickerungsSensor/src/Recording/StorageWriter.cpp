#include "StorageWriter.hpp"

#include "../Storage/Flash.hpp"

#include <Arduino.h>

void StorageWriter::init()
{
    Serial.println("Init storage ...");
}

namespace
{
    constexpr uint32_t stringBufferSize = 128;
    char stringBuffer[stringBufferSize] = {0};
}

bool StorageWriter::write_sample(float sample_time, float sample_value)
{

    File dataFile = Flash.get_fatfs().open(file_name, FILE_WRITE);
    if (!dataFile)
    {
        return false;
    }

    int t_left = round(sample_time);
    int seconds = t_left % 60;
    t_left /= 60;
    int minutes = t_left % 60;
    t_left /= 60;
    int hours = t_left;

    int len = snprintf(stringBuffer, stringBufferSize, "%d:%d:%d;%.2f", hours, minutes, seconds, sample_value);
    for (uint32_t i = 0; int(i) < len && i < stringBufferSize; i++)
    {
        if (stringBuffer[i] == '.')
            stringBuffer[i] = ',';
    }
    dataFile.println(stringBuffer);

    dataFile.close();

    Flash.sync();

    return true;
}

void StorageWriter::start(DateTime date_time)
{
    snprintf(folder_name, sizeof(folder_name), "%02d_%02d_%02d",
             date_time.year() % 100,
             date_time.month(),
             date_time.day());

    snprintf(file_name, sizeof(file_name), "%02d_%02d_%02d.csv",
             date_time.hour(),
             date_time.minute(),
             date_time.second());

    Flash.get_fatfs().chdir();
    Flash.get_fatfs().mkdir(folder_name);
    Flash.get_fatfs().chdir(folder_name);

    File dataFile = Flash.get_fatfs().open(file_name, FILE_WRITE);
    if (dataFile)
    {
        dataFile.println("Zeit(s);Distanz(mm)");
    }
    dataFile.close();
    Flash.sync();
}

void StorageWriter::finish()
{
}
