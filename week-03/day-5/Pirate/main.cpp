#include <iostream>
#include "Pirate.h"
#include "PirateNames.h"
#include "Ship.h"
#include <ctime>

int main(int argc, char * argv[])
{
    srand(time(NULL));
    Pirate pirate1;
    Pirate pirate2;

    for (int i = 0; i < 6; i++) {
        pirate1.howItsGoingMate();
    }

    std::cout << pirate1.getDrunkLevel() << std::endl;

    pirate1.die();
    pirate1.howItsGoingMate();
    pirate1.drinkSomeRum();
    pirate1.brawl(pirate2);

    std::vector<Pirate> myPirateVector;
    myPirateVector.push_back(pirate1);
    myPirateVector.push_back(pirate2);

    for (int i = 0; i < 38; i++) {
        myPirateVector.push_back(Pirate());
    }

    Ship ship1("\"The Great Armada\"");
    Ship ship2("\"The Almost Great Armada\"");
    ship1.fillShip();
    ship2.fillShip();

    std::cout << ship1.getAmountOfCrew() << std::endl;

    //Ship1 introduction
    std::cout << "The ship: " << ship1.getShipName() << " has  arrived, and it's captain called: " << ship1.getCaptainName() << std::endl;
    std::cout << "The captain consumed: " << ship1.captain.getDrunkLevel() << " beers, and now " << ship1.captain.CaptainStatus();
    std::cout << " The number of alive pirates in the crew: " << ship1.numberOfAlivePirates() << std::endl;
    //Ship2 introduction
    for (int i = 0; i < 2; i++) {
        ship2.captain.drinkSomeRum();
    }
    std::cout << ship2.getAmountOfCrew() << std::endl;

    ship2.captain.die();
    std::cout << "The ship: " << ship2.getShipName() << " has  arrived, and it's captain called: " << ship2.getCaptainName() << std::endl;
    std::cout << "The captain consumed: " << ship2.captain.getDrunkLevel() << " beers, and now " << ship2.captain.CaptainStatus();
    std::cout << " The number of alive pirates in the crew: " << ship2.numberOfAlivePirates() << std::endl;

    std::cout << ship2.getAmountOfCrew() << std::endl;


    return 0;
}