#include "F16.h"

F16::F16()
{
    _currentAmmo = 0;
    _baseDamage = 30;
    _maxAmmo = 8;
    _type = "F16";
}

F16::F16(int baseDamage) : Aircrafts(baseDamage)
{
    _currentAmmo = 0;
    _maxAmmo = 8;
    _type = "F16";
}

