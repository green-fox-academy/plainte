#include "Aircraft.h"

Aircraft::Aircraft()
{
    _type = "Aircraft";
    _currentAmmo = 0;
    _currentDamage = 0;
}

int Aircraft::fight()
{
    _currentDamage = _currentAmmo * _baseDamage;
    _currentAmmo = 0;
    return _currentDamage;
}

std::string Aircraft::getType()
{
    return _type;
}

std::string Aircraft::getStatus()
{
    std::string status = "Type " + _type + ", Ammo: " + std::to_string(_currentAmmo) + ", Base Damage: "
            + std::to_string(_baseDamage) + ", All Damage: " + std::to_string(getTotalDamage()) + "\n";
    return status;
}

bool Aircraft::isPriority()
{
    return !(_type == "F16");
}

int Aircraft::refill(int refillWith)
{
    int number = refillWith;
    if (number > 0) {
        for (int i = 0; i < _maxAmmo; i++) {
            if (number > 0 && _currentAmmo < _maxAmmo) {
                _currentAmmo++;
                number--;
            } else {
                break;
            }
        }
    }
    return number;
}

int Aircraft::getCurrentAmmo()
{
    return _currentAmmo;
}

int Aircraft::getMaxAmmo()
{
    return _maxAmmo;
}

void Aircraft::setCurrentAmmo()
{
    _currentAmmo++;
}

int Aircraft::getBaseDamage()
{
    return _baseDamage;
}

int Aircraft::getTotalDamage()
{
    return _currentAmmo * _baseDamage;
}



