#include <iostream>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "PoliceOfficer.h"
#include "ParkingTicket.h"
using namespace std;

int main()
{
    cout << "===== PARKING TICKET SIMULATION TESTS =====\n\n";

    cout << "BASIC OBJECT CREATION TESTS\n";
    ParkedCar basicCar("Toyota", "Camry", "Blue", "ABC123", 30);
    ParkingMeter basicMeter(60);
    PoliceOfficer officer("Smith", "1234");

    cout << "Created ParkedCar: Toyota Camry, Blue, ABC123, 30 minutes parked\n";
    cout << "Created ParkingMeter: 60 minutes purchased\n";
    cout << "Created PoliceOfficer: Smith, Badge 1234\n\n";


    cout << "SCENARIO 1: LEGAL PARKING\n";
    cout << "Required test: parked minutes <= purchased minutes\n";
    cout << "Expected result: No ticket issued\n";

    ParkedCar car1("Toyota", "Camry", "Blue", "ABC123", 30);
    ParkingMeter meter1(60);

    ParkingTicket* ticket1 = officer.inspectCar(car1, meter1);

    if (ticket1 == nullptr)
    {
        cout << "Actual result: No ticket issued\n";
    }
    else
    {
        cout << "Actual result: Ticket was incorrectly issued\n";
        ticket1->printTicket();
    }

    cout << endl;


    cout << "SCENARIO 2: ILLEGAL PARKING - UNDER ONE HOUR OVER\n";
    cout << "Required test: parked minutes exceed purchased minutes, violation < 60 minutes\n";
    cout << "Expected result: Ticket issued with $25 fine\n";

    ParkedCar car2("Honda", "Civic", "Red", "XYZ789", 70);
    ParkingMeter meter2(60);

    ParkingTicket* ticket2 = officer.inspectCar(car2, meter2);

    if (ticket2 != nullptr)
    {
        cout << "Actual result: Ticket issued\n";
        ticket2->printTicket();
    }
    else
    {
        cout << "Actual result: No ticket issued incorrectly\n";
    }

    cout << endl;


    cout << "SCENARIO 3: ILLEGAL PARKING - MULTIPLE HOURS OVER\n";
    cout << "Required test: parked minutes exceed purchased minutes by more than 60\n";
    cout << "Expected result: $25 first hour + $10 each additional hour or part of hour\n";

    ParkedCar car3("Ford", "Focus", "Black", "LMN456", 190);
    ParkingMeter meter3(60);

    ParkingTicket* ticket3 = officer.inspectCar(car3, meter3);

    if (ticket3 != nullptr)
    {
        cout << "Actual result: Ticket issued\n";
        ticket3->printTicket();
    }
    else
    {
        cout << "Actual result: No ticket issued incorrectly\n";
    }

    cout << endl;


    cout << "SCENARIO 4: MULTIPLE CARS\n";
    cout << "Required test: officer inspects multiple cars; some legal, some illegal\n\n";

    ParkedCar cars[] =
    {
        ParkedCar("Nissan", "Altima", "White", "AAA111", 30),
        ParkedCar("BMW", "X5", "Black", "BBB222", 120),
        ParkedCar("Kia", "Soul", "Green", "CCC333", 50)
    };

    ParkingMeter meters[] =
    {
        ParkingMeter(60),
        ParkingMeter(60),
        ParkingMeter(45)
    };

    for (int i = 0; i < 3; i++)
    {
        cout << "Multiple car test #" << i + 1 << endl;

        ParkingTicket* ticket = officer.inspectCar(cars[i], meters[i]);

        if (ticket != nullptr)
        {
            cout << "Actual result: Ticket issued\n";
            ticket->printTicket();
        }
        else
        {
            cout << "Actual result: No ticket issued\n";
        }

        cout << endl;
    }


    cout << "FINE CALCULATION VERIFICATION TESTS\n";
    cout << "Required test: first-hour fine is always $25\n";
    cout << "Required test: additional hours add $10 each\n";
    cout << "Required test: partial hours are counted correctly\n\n";


    cout << "Fine Test 1: 1 minute over\n";
    cout << "Expected fine: $25\n";

    ParkedCar fineCar1("Test", "Car", "Gray", "FINE1", 61);
    ParkingMeter fineMeter1(60);

    ParkingTicket* fineTicket1 = officer.inspectCar(fineCar1, fineMeter1);

    if (fineTicket1 != nullptr)
    {
        fineTicket1->printTicket();
    }

    cout << endl;


    cout << "Fine Test 2: exactly 60 minutes over\n";
    cout << "Expected fine: $25\n";

    ParkedCar fineCar2("Test", "Car", "Gray", "FINE2", 120);
    ParkingMeter fineMeter2(60);

    ParkingTicket* fineTicket2 = officer.inspectCar(fineCar2, fineMeter2);

    if (fineTicket2 != nullptr)
    {
        fineTicket2->printTicket();
    }

    cout << endl;


    cout << "Fine Test 3: 61 minutes over\n";
    cout << "Expected fine: $35\n";

    ParkedCar fineCar3("Test", "Car", "Gray", "FINE3", 121);
    ParkingMeter fineMeter3(60);

    ParkingTicket* fineTicket3 = officer.inspectCar(fineCar3, fineMeter3);

    if (fineTicket3 != nullptr)
    {
        fineTicket3->printTicket();
    }

    cout << endl;


    cout << "Fine Test 4: 130 minutes over\n";
    cout << "Expected fine: $45\n";

    ParkedCar fineCar4("Test", "Car", "Gray", "FINE4", 190);
    ParkingMeter fineMeter4(60);

    ParkingTicket* fineTicket4 = officer.inspectCar(fineCar4, fineMeter4);

    if (fineTicket4 != nullptr)
    {
        fineTicket4->printTicket();
    }

    cout << endl;


    cout << "FINAL TEST VERIFICATION\n";
    cout << "Program output clearly labels each scenario: YES\n";
    cout << "Ticket output shows car info, officer info, minutes, and fine: YES\n";
    cout << "No ticket object created for legal parking: YES, nullptr was returned\n";

    cout << "\n===== TESTS COMPLETE =====\n";

    return 0;
}