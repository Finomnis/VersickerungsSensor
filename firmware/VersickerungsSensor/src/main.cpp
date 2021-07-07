#include <Arduino.h>
#include <Wire.h>

#include <Tof10120.hpp>

#include "peripherals.hpp"

TOF10120 sensor(I2C_DEVICES::SENSOR_TOF10120);
ValueWatcher<uint16_t> distance_value = sensor.create_watcher();

void setup()
{
    Wire.begin();

    Serial.begin(9600);
    while (!Serial)
        ;

    Serial.println("\nVersickerungs Sensor");
}

void loop()
{
    sensor.update();

    if (distance_value.new_value_available())
    {
        Serial.print("Distance: ");
        if (distance_value.is_valid())
        {
            Serial.print(distance_value.get_value());
        }
        else
        {
            Serial.print("---");
        }
        Serial.println(" mm");
    }
}
