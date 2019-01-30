#include <iostream>
#include "car.h"
#include "station.h"

int main(int argc, char * argv[]) {
    Car car1(120, 200);
    Car car2(20, 300);
    Car car3(0, 450);
    Car car4(70, 220);
    Car car5(210, 300);

    Station station;

    station.fill(car1);
    station.fill(car2);
    station.fill(car3);
    station.fill(car4);
    station.fill(car5);


    return 0;
}