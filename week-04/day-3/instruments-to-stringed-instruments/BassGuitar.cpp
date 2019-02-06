#include <iostream>
#include "BassGuitar.h"

BassGuitar::BassGuitar()
{
    _name = "Bass Guitar";
    _numberOfStrings = 4;
}

BassGuitar::BassGuitar(int numberOfStrings)
{
    _name = "Bass Guitar";
    _numberOfStrings = numberOfStrings;
}

std::string BassGuitar::sound()
{
    return "Duum-duum-duum";
}

void BassGuitar::play()
{
    std::cout << _name << ", a " << _numberOfStrings
    << "-stringed instrument that goes " << sound() << std::endl;
}
