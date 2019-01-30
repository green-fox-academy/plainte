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

void Animal::setHunger(int hunger_)
{
    hunger = hunger_;
}

void Animal::setThirst(int thirst_)
{
    thirst = thirst_;
}

int Animal::getHunger()
{
    return hunger;
}

int Animal::getThirst()
{
    return thirst;
}