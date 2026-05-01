#ifndef PARKINGTICKET_H
#define PARKINGTICKET_H

#include "ParkedCar.h"
#include <string>
using namespace std;

class ParkingTicket
{
private:
    ParkedCar car;
    string officerName;
    string badgeNumber;
    int fine;

    void calculateFine(int overMinutes);

public:
    ParkingTicket(ParkedCar c, string name, string badge, int overMinutes, int purchasedTime);
    int purchased;
    void printTicket() const;
};

#endif
