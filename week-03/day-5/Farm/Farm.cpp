#include "Farm.h"
#include <iostream>
#include <vector>

Farm::Farm(std::vector<Animal>& animal, int freeSpaces)
{
    animalObject = animal;
    _freeSpaces = freeSpaces;
}

void Farm::breed()
{
    if (_freeSpaces > 0){
        animalObject.push_back(Animal());

    }
}

void Farm::slaughter()
{   int temp = animalObject[0].getHunger();
    for (unsigned int i = 0; i < animalObject.size(); i++) {
        if ( animalObject[i].getHunger() < temp) {
            temp = animalObject[i].getHunger();
        }
    }
    for (unsigned int j = 0; j < animalObject.size(); j++) {
        if (animalObject[j].getHunger() == temp) {
            animalObject.erase(animalObject.begin() + j);
        }
    }
}

unsigned int Farm::getAmountOfAnimals()
{
    return animalObject.size();
}

int Farm::getAmountOfFreeSpaces()
{
    return _freeSpaces;
}

std::vector<Animal> &Farm::getAnimalObject()
{
    return animalObject;
}

