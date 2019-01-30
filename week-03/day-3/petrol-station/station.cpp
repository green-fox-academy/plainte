#include "station.h"
#include <string>
#include "car.h"
#include <iostream>

Station::Station()
{
    gasAmount = 10000;
}

void Station::fill(Car& car) {
    while (!car.isFull()) {
        car.gasAmount++;
        gasAmount--;
        std::cout << "Filling car!" << std::endl;
    }
    std::cout << gasAmount << std::endl;
}