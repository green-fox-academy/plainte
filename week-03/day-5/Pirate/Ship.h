#include "Pirate.h"
#include "PirateNames.h"
#include <vector>
#ifndef PIRATE_SHIP_H
#define PIRATE_SHIP_H


class Ship
{
public:
    Ship();
    Ship(std::vector<Pirate>& crew_);
    Ship(std::string shipName_);
    unsigned int getAmountOfCrew();
    void fillShip();
    std::string getCaptainName();
    std::string getShipName();
    Pirate captain;
    int numberOfAlivePirates();
    std::vector<Pirate> getCrew();
private:
    std::vector<Pirate> crew;
    std::string shipName;

};


#endif //PIRATE_SHIP_H
