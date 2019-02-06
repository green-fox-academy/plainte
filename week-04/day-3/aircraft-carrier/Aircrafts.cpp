#include "Aircrafts.h"

Aircrafts::Aircrafts()
{
    _currentAmmo = 0;
    _baseDamage = 0;
    _maxAmmo = 100;
    _type = "Aircraft";
}

Aircrafts::Aircrafts(int baseDamage)
{
    _currentAmmo = 0;
    _maxAmmo = 100;
    _type = "Aircraft";
}

void Aircrafts::printMaxAmmo()
{
    std::cout << "Max ammo: " << _maxAmmo << std::endl;
}

void Aircrafts::printBaseDamage()
{
    std::cout << "Base damage: " << _baseDamage << std::endl;
}

int Aircrafts::fight()
{
    int damageDealt = _baseDamage * _currentAmmo;
    _currentAmmo = 0;
    return damageDealt;
}

int Aircrafts::refill(int refillingWithThis)
{
    if (refillingWithThis > 0) {
        for (int i = 0; i < _maxAmmo; i++) {
            if (refillingWithThis > 0) {
                refillingWithThis--;
                _currentAmmo++;
            }
        }
    }
    return refillingWithThis;
}


void Aircrafts::printCurrentAmmo()
{
    std::cout << "The current ammo is: " << _currentAmmo << std::endl;
}

std::string Aircrafts::getType()
{
    return _type;
}

void Aircrafts::getStatus()
{
    std::cout << "Type " << _type << ", Ammo: " << _currentAmmo << ", Base Damage: "
    << _baseDamage << ", All Damage: " << _baseDamage * _currentAmmo << std::endl;
}

void Aircrafts::isPriority()
{
    _isPriority = false;
    if(_isPriority) {
        std::cout << "The " << _type << " is priority in the ammo fill queue" << std::endl;
    } else {
        std::cout << "The " << _type << " is not priority in the ammo fill queue" << std::endl;
    }
}

