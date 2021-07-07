#include "Tof10120.hpp"

#include <Wire.h>

constexpr unsigned long SENSOR_MEASUREMENT_DELAY_MS = 30;

TOF10120::TOF10120(uint8_t i2c_addr)
    : i2c_addr{i2c_addr}
{
}

void TOF10120::update_request()
{
    if (!requestPending)
    {
        // Request sensor to measure distance
        Wire.beginTransmission(i2c_addr);
        Wire.write(byte(0));
        uint8_t error = Wire.endTransmission();
        if (error != 0)
        {
            // TODO publish error state to data store
            Serial.println("ERROR: Can't reach sensor");
            return;
        }

        requestPending = true;
        responseExpected = millis() + SENSOR_MEASUREMENT_DELAY_MS;
    }
}

void TOF10120::update_response()
{
    if (requestPending && millis() >= responseExpected)
    {
        requestPending = false;

        // Read response
        Wire.requestFrom(i2c_addr, 2);
        if (Wire.available() != 2)
        {
            // TODO publish error state to data store
            Serial.println("ERROR: Can't reach sensor");
            return;
        }

        unsigned char hi = Wire.read();
        unsigned char lo = Wire.read();
        unsigned short distance = hi;
        distance = distance << 8;
        distance |= lo;

        // TODO publish sensor value to data store
        Serial.print("Sensor value: ");
        Serial.print(distance);
        Serial.println(" mm");
    }
}

void TOF10120::update()
{
    update_response();
    update_request();
}
