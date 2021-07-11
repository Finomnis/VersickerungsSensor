#include "StorageWriter.hpp"

#include <Arduino.h>

void StorageWriter::init()
{
    Serial.println("Init storage ...");
}

void StorageWriter::write_sample(float sample_time, float sample_value)
{
    Serial.print("Writing to '");
    Serial.print(folder_name);
    Serial.print("/");
    Serial.print(file_name);
    Serial.print("': ");
    Serial.print(sample_time);
    Serial.print(",");
    Serial.print(sample_value);
    Serial.println();
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
}

void StorageWriter::finish()
{
}
