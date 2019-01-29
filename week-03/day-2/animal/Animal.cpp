#include "Animal.h"
#include <iostream>

Animal::Animal() {
    hunger = 50;
    thirst = 50;
}

void Animal::eat() {
    hunger--;
}
void Animal::drink() {
    thirst--;
}
void Animal::play() {
    hunger++;
    thirst++;
}