#include <iostream>
#include "car.h"
#include "station.h"

int main(int argc, char * argv[]) {
    Car car1(50, 70);
    Car car2(20, 90);
    Car car3(0, 45);
    Car car4(70, 80);
    Car car5(50, 55);

    Station station;

    station.fill(car1);
    station.fill(car2);
    station.fill(car3);
    station.fill(car4);
    station.fill(car5);


    return 0;
}