#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main()
{
    Animal animal1;
    Animal animal2;

    animal1.eat();
    for (int i = 0; i < 5; i++) {
        animal2.eat();
    }
    std::vector<Animal> myAnimals;
    myAnimals.push_back(animal1);
    myAnimals.push_back(animal2);

    Farm farm(myAnimals, 50);

    for (int i = 0; i < 46; i++) {
        farm.breed();
    }

    std::cout << farm.getAmountOfAnimals() << " " << farm.getAmountOfFreeSpaces() << std::endl;

    farm.slaughter();
    std::cout << farm.getAmountOfAnimals() << " " << farm.getAmountOfFreeSpaces() << std::endl;
    farm.slaughter();
    std::cout << farm.getAmountOfAnimals() << " " << farm.getAmountOfFreeSpaces() << std::endl;
    farm.slaughter();
    std::cout << farm.getAmountOfAnimals() << " " << farm.getAmountOfFreeSpaces() << std::endl;

    return 0;
}