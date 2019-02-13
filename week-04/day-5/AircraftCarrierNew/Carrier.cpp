#include "Carrier.h"

#include <iostream>

void Carrier::add(Aircraft* aircraft)
{
    _aircraft.push_back(aircraft);
}

Carrier::Carrier(int ammo, int hp)
{
    _ammo = ammo;
    _hp = hp;
}

void Carrier::fill()
{
    try {
        int totalAmmoNeeded = 0;
        for (unsigned int i = 0; i < _aircraft.size(); i++) {
            totalAmmoNeeded += (_aircraft[i]->getMaxAmmo() - _aircraft[i]->getCurrentAmmo());
        }
        if (_ammo < 0) {
            throw -1;
        }
        if (_ammo == 0) {
            throw "exception";
        } else if (totalAmmoNeeded > _ammo) {
            for (unsigned int i = 0; i < _aircraft.size(); i++) {
                if (_aircraft[i]->isPriority() && _aircraft[i]->getCurrentAmmo() < _aircraft[i]->getMaxAmmo()) {
                    if (_ammo == 0) {
                        throw "exception";
                    } else {
                        while (_aircraft[i]->getCurrentAmmo() != _aircraft[i]->getMaxAmmo()) {
                            if (_ammo == 0) {
                                throw "exception";
                            } else {
                                _aircraft[i]->setCurrentAmmo();
                                _ammo--;
                            }
                        }
                    }
                }
            }
            if (_ammo > 0) {
                for (unsigned int i = 0; i < _aircraft.size(); i++) {
                    if (!_aircraft[i]->isPriority() && _aircraft[i]->getCurrentAmmo() < _aircraft[i]->getMaxAmmo()) {
                        if (_ammo == 0) {
                            throw "exception";
                        } else {
                            while (_aircraft[i]->getCurrentAmmo() != _aircraft[i]->getMaxAmmo()) {
                                if (_ammo == 0) {
                                    throw "exception";
                                } else {
                                    _aircraft[i]->setCurrentAmmo();
                                    _ammo--;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            for (unsigned int i = 0; i < _aircraft.size(); i++) {
                if (_aircraft[i]->getCurrentAmmo() < _aircraft[i]->getMaxAmmo()) {
                    if (_ammo == 0) {
                        throw "exception";
                    } else {
                        while (_aircraft[i]->getCurrentAmmo() != _aircraft[i]->getMaxAmmo()) {
                            if (_ammo == 0) {
                                throw "exception";
                            } else {
                                _aircraft[i]->setCurrentAmmo();
                                _ammo--;
                            }
                        }
                    }
                }
            }
        }
    } catch(int &e) {
        std::cout << "Are u an idiot? It should have at least 0 ammo!!!!!" << std::endl;
    } catch(...) {
        std::cout << "Sorry, the ammo ran out. Please, check back later!" << std::endl;
    }
}

int Carrier::getCarrierAmmo()
{
    return _ammo;
}

void Carrier::fight(Carrier &carrier)
{
    int totalDamage = 0;
    for (unsigned int i = 0; i < _aircraft.size(); i++) {
        totalDamage += _aircraft[i]->fight();
    }
    if (totalDamage > carrier._hp) {
        carrier._hp = 0;
    } else {
        carrier._hp -= totalDamage;
    }
}

int Carrier::getHP()
{
    return _hp;
}

std::string Carrier::getStatus()
{
    int totalDamage = 0;
    for (unsigned int i = 0; i < _aircraft.size(); i++) {
        totalDamage += _aircraft[i]->getCurrentAmmo() * _aircraft[i]->getBaseDamage();
    }

    if (getHP() > 0) {
        std::string status = "HP: " + std::to_string(getHP()) + ", Aircraft count: " + std::to_string(_aircraft.size())
                             + ", Ammo storage: " + std::to_string(_ammo) + ", Total damage: " + std::to_string(totalDamage) + "\n"
                             + "Aircrafts:\n";
        for (unsigned int i = 0; i < _aircraft.size(); i++) {
            status.append(_aircraft[i]->getStatus());
        }
        return status;
    }
    return "It's dead Jim :(";
}
