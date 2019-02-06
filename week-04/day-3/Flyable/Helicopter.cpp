#include <iostream>
#include "Helicopter.h"

Helicopter::Helicopter()
{
    _type = "UH-1H";
    _model = "Gunship";
    _manufacturer = "Bell";
}

Helicopter::Helicopter(std::string type, std::string model, std::string manufacturer)
{
    _type = type;
    _model = model;
    _manufacturer = manufacturer;
}

void Helicopter::land()
{
    std::cout << "The " << _manufacturer << " " << _type << " "<< _model
    << " is landing!"<< std::endl;
}

void Helicopter::fly()
{
    std::cout << "The " << _manufacturer << " " << _type << " " << _model
    << " is flying!" << std::endl;
}

void Helicopter::takeOff()
{
    std::cout << "The " << _manufacturer << " " << _type << " " << _model
              << " take off!" << std::endl;
}
