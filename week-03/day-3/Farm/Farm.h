#ifndef FARM_FARM_H
#define FARM_FARM_H
#include <iostream>
#include <vector>
#include "Animal.h"


class Farm
{
public:
    Farm(std::vector<Animal>& animal, int freeSpaces);
    void breed();
    void slaughter();
    unsigned int getAmountOfAnimals();
    int getAmountOfFreeSpaces();
    const std::vector<Animal> &getAnimalObject() const;
private:
    std::vector<Animal> animalObject;
    int _freeSpaces;


};


#endif //FARM_FARM_H
