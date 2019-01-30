#include <string>
#include "car.h"

#ifndef PETROL_STATION_STATION_H
#define PETROL_STATION_STATION_H


class Station
{
public:
    Station();

    void fill(Car& car);
    int gasAmount;
};

#endif //PETROL_STATION_STATION_H
