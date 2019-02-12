#include "Farm.h"

Farm::Farm()
{
    _freeSpaces = 50;
}
Farm::Farm(const std::vector<Animal> animals, int freeSpaces)
{
    _animals = animals;
    _freeSpaces = freeSpaces - animals.size();
}

void Farm::breed()
{
    if (_freeSpaces > 0) {
        _animals.emplace_back(Animal());
        _freeSpaces--;
    }
}

void Farm::slaughter()
{
    int temp = _animals[0].getHunger();
    for (unsigned int i = 0; i < _animals.size(); i++) {
        if (_animals[i].getHunger() < temp) {
            temp = _animals[i].getHunger();
        }
    }
    for (unsigned int j = 0; j < _animals.size(); j++) {
        if (_animals[j].getHunger() == temp) {
            _animals.erase(_animals.begin() + j);
            _freeSpaces++;
            break;
        }
    }
}

int Farm::getAmountOfFreeSpaces()
{
    return _freeSpaces;
}

unsigned int Farm::getAmountOfAnimals()
{
    return _animals.size();
}
