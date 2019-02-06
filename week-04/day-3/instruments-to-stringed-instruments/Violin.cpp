#include <iostream>
#include "Violin.h"

Violin::Violin()
{
    _name = "Violin";
    _numberOfStrings = 4;
}

Violin::Violin(int numberOfStrings)
{
    _name = "Violin";
    _numberOfStrings = numberOfStrings;
}

std::string Violin::sound()
{
    return "Screech";
}

void Violin::play()
{
    std::cout << _name << ", a " << _numberOfStrings
    << "-stringed instrument that goes " << sound() << std::endl;
}
