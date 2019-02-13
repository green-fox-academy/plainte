#ifndef AIRCRAFTCARRIERNEW_CARRIER_H
#define AIRCRAFTCARRIERNEW_CARRIER_H

#include <vector>
#include "Aircraft.h"

class Carrier
{
public:
    Carrier(int ammo, int hp);
    void add(Aircraft* aircraft);
    void fill();
    int getCarrierAmmo();
    void fight(Carrier& carrier);
    int getHP();
    std::string getStatus();
private:
    std::vector<Aircraft*> _aircraft;
    int _ammo;
    int _hp;

};


#endif //AIRCRAFTCARRIERNEW_CARRIER_H
