#ifndef AIRCRAFT_CARRIER_F35_H
#define AIRCRAFT_CARRIER_F35_H


#include "Aircrafts.h"

class F35 : public Aircrafts
{
public:
    F35();
    F35(int baseDamage);
    void isPriority();
};


#endif //AIRCRAFT_CARRIER_F35_H
