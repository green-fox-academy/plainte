#include "F35.h"

F35::F35()
{
    _currentAmmo = 0;
    _baseDamage = 50;
    _maxAmmo = 12;
    _type = "F35";
}

F35::F35(int baseDamage) : Aircrafts(baseDamage)
{
    _currentAmmo = 0;
    _maxAmmo = 12;
    _type = "F35";
}

void F35::isPriority()
{
    _isPriority = true;
    if(_isPriority) {
        std::cout << "The " << _type << " is priority in the ammo fill queue" << std::endl;
    } else {
        std::cout << "The " << _type << " is not priority in the ammo fill queue" << std::endl;
    }
}
