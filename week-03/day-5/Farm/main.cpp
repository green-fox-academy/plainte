#include <iostream>
#include "Animal.h"
#include "Farm.h"
#include <vector>

int main() {
    Animal duck;
    Animal lion;
    Animal giraffe;

    for (int i = 0; i < 5; i++) {
        duck.eat();
    }

    std::cout << duck.getHunger() << std::endl;

    lion.play();

    std::cout << lion.getHunger() << " " << lion.getThirst() << std::endl;

    while (giraffe.getThirst() != 0){
        giraffe.drink();
    }

    std::cout << giraffe.getThirst() << std::endl;

    std::vector<Animal> myFarmVector;
    myFarmVector.push_back(duck);
    myFarmVector.push_back(lion);
    myFarmVector.push_back(giraffe);

    Farm AnimalFarm1(myFarmVector, 50);
    for (int i = 0; i < AnimalFarm1.getAmountOfFreeSpaces(); i++) {
        AnimalFarm1.breed();
    }

    std::cout << AnimalFarm1.getAmountOfAnimals() << std::endl;

    for (unsigned int i = 0; i < AnimalFarm1.getAnimalObject().size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 20) {
                AnimalFarm1.getAnimalObject().at(i).eat();
            } else if (i == 25 && j == 1) {
                AnimalFarm1.getAnimalObject().at(i).eat();
            } else if (i == 30 && j == 2) {
                AnimalFarm1.getAnimalObject().at(i).eat();
            } else {
                AnimalFarm1.getAnimalObject().at(i).play();
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        AnimalFarm1.slaughter();
    }

    std::cout << AnimalFarm1.getAmountOfAnimals() << std::endl;
    return 0;
}