#include <iostream>
#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar()
{
    _name = "Electric Guitar";
    _numberOfStrings = 6;
}

ElectricGuitar::ElectricGuitar(int numberOfStrings)
{
    _name = "Electric Guitar";
    _numberOfStrings = numberOfStrings;
}

std::string ElectricGuitar::sound()
{
    return "Twang";
}

void ElectricGuitar::play()
{
    std::cout << _name << ", a " << _numberOfStrings
    << "-stringed instrument that goes " << sound() << std::endl;
}
