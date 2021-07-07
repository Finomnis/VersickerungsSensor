#include <Arduino.h>

#include <Wire.h>

#include <Tof10120.hpp>

#include "peripherals.hpp"

TOF10120 sensor(I2C_DEVICES::SENSOR_TOF10120);

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
}
