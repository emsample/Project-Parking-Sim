#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>
using namespace std;

class ParkedCar
{
private:
    string make, model, color, license;
    int minutesParked;

public:
    ParkedCar(string mk, string md, string c, string lic, int min);

    string getMake() const;
    string getModel() const;
    string getColor() const;
    string getLicense() const;
    int getMinutesParked() const;
};

#endif
