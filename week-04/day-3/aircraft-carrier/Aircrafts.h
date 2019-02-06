#ifndef AIRCRAFT_CARRIER_AIRCRAFTS_H
#define AIRCRAFT_CARRIER_AIRCRAFTS_H
#include <iostream>

class Aircrafts
{
public:
    Aircrafts();
    Aircrafts(int baseDamage);
    void printMaxAmmo();
    void printBaseDamage();
    int fight();
    int refill(int refillingWithThis);
    void printCurrentAmmo();
    std::string getType();
    void getStatus();
    virtual void isPriority();
protected:
    int _currentAmmo;
    int _baseDamage;
    int _maxAmmo;
    bool _isPriority;
    std::string _type;

};


#endif //AIRCRAFT_CARRIER_AIRCRAFTS_H
