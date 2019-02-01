#include "Ship.h"
#include "Pirate.h"
#include "PirateNames.h"
#include <ctime>

Ship::Ship()
{

}
Ship::Ship(std::vector<Pirate>& crew_)
{
    crew = crew_;
}

unsigned int Ship::getAmountOfCrew()
{
    return crew.size();
}

void Ship::fillShip()
{
    for (int  i = 0; i < rand(); i++) {
        crew.push_back(Pirate());
    }
    crew[0] = captain;
}

std::string Ship::getCaptainName()
{
    return captain.getPirateName();
}
Ship::Ship(std::string shipName_)
{
    shipName = shipName_;
}
std::string Ship::getShipName()
{
    return shipName;
}

int Ship::numberOfAlivePirates()
{
    int temp = 0;
    for (unsigned int i = 1; i < crew.size(); i++) {
        if (crew[i].isAliveAndAwake()) {
            temp += 1;
        }
    }
    return temp;
}

std::vector<Pirate> Ship::getCrew()
{
    for (unsigned int i = 0; i < crew.size(); i++) {
        crew.erase(crew.begin());
    }
    return crew;
}


