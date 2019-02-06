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
