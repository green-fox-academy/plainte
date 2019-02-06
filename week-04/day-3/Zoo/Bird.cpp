#include <iostream>
#include "Bird.h"

Bird::Bird()
{
    _name = "Bird";
}

Bird::Bird(std::string name)
{
    _name = name;
}

std::string Bird::getName()
{
    return _name;
}

std::string Bird::breed()
{
    return "laying eggs.";
}

void Bird::land()
{
    std::cout << "The " << _name << " is landing!" << std::endl;
}

void Bird::fly()
{
    std::cout << "The " << _name << " is flying!" << std::endl;
}

void Bird::takeOff()
{
    std::cout << "The " << _name << " takes off!" << std::endl;
}
