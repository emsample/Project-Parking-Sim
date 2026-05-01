#include "ParkedCar.h"

ParkedCar::ParkedCar(string mk, string md, string c, string lic, int min)
{
    make = mk;
    model = md;
    color = c;
    license = lic;
    minutesParked = min;
}

string ParkedCar::getMake() const { return make; }
string ParkedCar::getModel() const { return model; }
string ParkedCar::getColor() const { return color; }
string ParkedCar::getLicense() const { return license; }
int ParkedCar::getMinutesParked() const { return minutesParked; }