#ifndef AIRCRAFTCARRIERNEW_AIRCRAFT_H
#define AIRCRAFTCARRIERNEW_AIRCRAFT_H

#include <string>

class Aircraft
{
public:
    Aircraft();
    int fight();
    int refill(int refillWith);
    std::string getType();
    std::string getStatus();
    bool isPriority();
    int getCurrentAmmo();
    int getMaxAmmo();
    void setCurrentAmmo();
    int getBaseDamage();
    int getTotalDamage();
protected:
    int _maxAmmo;
    int _baseDamage;
    int _currentAmmo;
    int _currentDamage;
    std::string _type;
    int _totalDamage;

};


#endif //AIRCRAFTCARRIERNEW_AIRCRAFT_H
