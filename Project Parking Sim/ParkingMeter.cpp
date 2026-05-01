#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(int min)
{
    minutesPurchased = min;
}

int ParkingMeter::getMinutesPurchased() const
{
    return minutesPurchased;
}