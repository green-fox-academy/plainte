#include <iostream>
#include <vector>
#include "F16.h"
#include "F35.h"

int main(int argc, char * argv[])
{
    F16 aircraft1;
    std::cout << aircraft1.refill(10) << std::endl;
    aircraft1.printCurrentAmmo(); //check currentAmmo
    std::cout << aircraft1.fight() << std::endl; //prints dmg dealt
    aircraft1.printCurrentAmmo(); //currentAmmo correctly set to 0 after fight()
    std::cout << aircraft1.getType() << std::endl;

    aircraft1.refill(4);
    aircraft1.getStatus();

    //Testing isPriority
    F35 aircraftF35_1;
    F16 aircraftF16_1;

    aircraftF16_1.isPriority();
    aircraftF35_1.isPriority();

    std::vector<Aircrafts*> airCrafts;
    airCrafts.push_back(&aircraft1);
    airCrafts.push_back(&aircraftF16_1);
    airCrafts.push_back(&aircraftF35_1);


    return 0;
}