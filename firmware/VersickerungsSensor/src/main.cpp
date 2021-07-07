#include <Arduino.h>

#include <Wire.h>

void setup()
{
    Wire.begin();

    Serial.begin(9600);
    while (!Serial)
        ;

    Serial.println("\nI2C Scanner");
}

unsigned short readDistance(bool &success)
{
    Wire.beginTransmission(0x52);
    Wire.write(byte(0));
    uint8_t error = Wire.endTransmission();
    if (error != 0)
    {
        success = false;
        return 0;
    }

    delay(30);

    Wire.requestFrom(0x52, 2);
    if (Wire.available() != 2)
    {
        success = false;
        return 0;
    }

    unsigned char hi = Wire.read();
    unsigned char lo = Wire.read();
    unsigned short distance = hi;
    distance = distance << 8;
    distance |= lo;

    return distance;
}

void loop()
{
    byte error, address;
    int nDevices;

    Serial.println("Scanning...");

    nDevices = 0;
    for (address = 1; address < 127; address++)
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("I2C device found at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println("  !");

            nDevices++;
        }
        else if (error == 4)
        {
            Serial.print("Unknown error at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.println(address, HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
        Serial.println("done\n");

    Serial.println("Reading range:");

    constexpr uint32_t filter_size = 150;

    bool success = true;
    uint32_t distance_sum = 0;
    for (uint32_t i = 0; i < filter_size; i++)
    {
        distance_sum += readDistance(success);
    }

    if (!success)
    {
        Serial.println("Error reading distance");
        return;
    }

    Serial.print("   ");
    Serial.print(distance_sum / float(filter_size));
    Serial.println(" mm");
}
