#include <iostream>
#include "Animal.h"

int main() {
    Animal duck;
    for (int i = 0; i < 5; i++) {
        duck.eat();
    }

    std::cout << duck.hunger << std::endl;

    Animal lion;
    lion.play();

    std::cout << lion.hunger << " " << lion.thirst << std::endl;

    Animal giraffe;
    while (giraffe.thirst != 0){
        giraffe.drink();
    }

    std::cout << giraffe.thirst << std::endl;

    return 0;
}