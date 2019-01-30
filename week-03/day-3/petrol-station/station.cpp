#include "station.h"
#include <string>
#include "car.h"
#include <iostream>

Station::Station()
{
    gasAmount = 1000;
}

void Station::fill(Car& car) {
    while (!car.isFull()) {
        if (gasAmount == 0) {
            std::cout << "Sorry, the Station is out of gas!" << std::endl;
            exit(EXIT_SUCCESS);
        } else {
            car.gasAmount++;
            gasAmount--;
            std::cout << "Filling car!" << std::endl;
        }
    }
    std::cout << gasAmount << std::endl;
}