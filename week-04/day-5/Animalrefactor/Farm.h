#ifndef ANIMALREFACTOR_FARM_H
#define ANIMALREFACTOR_FARM_H

#include "Animal.h"
#include <vector>

class Farm
{
public:
    Farm();
    Farm(const std::vector<Animal> animals, int freeSpaces);
    void breed();
    void slaughter();
    unsigned int getAmountOfAnimals();
    int getAmountOfFreeSpaces();
private:
    std::vector<Animal> _animals;
    int _freeSpaces;
};


#endif //ANIMALREFACTOR_FARM_H
