#include "Farm.h"
#include <iostream>
#include <vector>

Farm::Farm(std::vector<Animal>& animal, int freeSpaces)
{
    animalObject = animal;
    _freeSpaces = freeSpaces;
}
