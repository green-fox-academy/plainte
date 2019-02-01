#include <iostream>
#include "Pirate.h"
#include "PirateNames.h"
#include <ctime>

int main(int argc, char * argv[]) {
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


    return 0;
}