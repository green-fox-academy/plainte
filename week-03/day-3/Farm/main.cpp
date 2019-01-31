#include <iostream>
#include "Animal.h"
#include "Farm.h"

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



    return 0;
}