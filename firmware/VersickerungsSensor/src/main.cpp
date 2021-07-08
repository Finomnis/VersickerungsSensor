#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <Tof10120.hpp>
#include <Logic.hpp>

#include "peripherals.hpp"

TOF10120 sensor(I2C_DEVICES::SENSOR_TOF10120);
ValueWatcher<uint16_t> distance_value{&sensor.get_value()};

void setup()
{
    Wire.begin();

    Serial.begin(9600);
    while (!Serial)
        delay(100);

    Serial.println("\nVersickerungs Sensor");

    // Initialize logic
    Logic::init();
}

void loop()
{
    sensor.update();

    Logic::update();
}
