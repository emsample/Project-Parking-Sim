#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(string n, string b)
{
    name = n;
    badge = b;
}

ParkingTicket* PoliceOfficer::inspectCar(ParkedCar car, ParkingMeter meter)
{
    int parked = car.getMinutesParked();
    int allowed = meter.getMinutesPurchased();

    if (parked > allowed)
    {
        int over = parked - allowed;
        return new ParkingTicket(car, name, badge, over);
    }

    return nullptr;
}