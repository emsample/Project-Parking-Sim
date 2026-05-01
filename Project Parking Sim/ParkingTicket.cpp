#include "ParkingTicket.h"
#include <iostream>
using namespace std;

ParkingTicket::ParkingTicket(ParkedCar c, string name, string badge, int overMinutes)
    : car(c)
{
    officerName = name;
    badgeNumber = badge;
    calculateFine(overMinutes);
}

void ParkingTicket::calculateFine(int overMinutes)
{
    fine = 25;

    if (overMinutes > 60)
    {
        int extraHours = (overMinutes - 1) / 60;
        fine += extraHours * 10;
    }
}

void ParkingTicket::printTicket() const
{
    cout << "\n--- PARKING TICKET ---\n";
    cout << car.getMake() << " " << car.getModel() << " (" << car.getColor() << ")\n";
    cout << "License: " << car.getLicense() << endl;
    cout << "Fine: $" << fine << endl;
    cout << "Officer: " << officerName << " (Badge " << badgeNumber << ")\n";
}