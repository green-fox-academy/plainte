#include <iostream>
#include "Animal.h"

int main() {
    Animal duck;
    for (int i = 0; i < 5; i++) {
        duck.eat();
    }

    std::cout << duck.getHunger() << std::endl;

    Animal lion;
    lion.play();

    std::cout << lion.getHunger() << " " << lion.getThirst() << std::endl;

    Animal giraffe;
    while (giraffe.getThirst() != 0){
        giraffe.drink();
    }

    std::cout << giraffe.getThirst() << std::endl;

    return 0;
}