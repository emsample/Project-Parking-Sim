#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include <string>
using namespace std;

class PoliceOfficer
{
private:
    string name;
    string badge;

public:
    PoliceOfficer(string n, string b);

    ParkingTicket* inspectCar(ParkedCar car, ParkingMeter meter);
};

#endif