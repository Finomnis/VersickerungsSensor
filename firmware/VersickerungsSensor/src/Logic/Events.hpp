#pragma once

#include "tinyfsm.hpp"

struct PressedButtonA : tinyfsm::Event
{
};

struct PressedButtonB : tinyfsm::Event
{
};

struct PressedButtonC : tinyfsm::Event
{
};

struct LongPressedButtonA : tinyfsm::Event
{
};

struct LongPressedButtonB : tinyfsm::Event
{
};

struct LongPressedButtonC : tinyfsm::Event
{
};

struct EnterBatteryLowPowerstate : tinyfsm::Event
{
};

struct LeaveBatteryLowPowerstate : tinyfsm::Event
{
};
