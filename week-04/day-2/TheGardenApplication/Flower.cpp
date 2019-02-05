#include <iostream>
#include "Flower.h"

Flower::Flower()
{
    _color = Color::YELLOW;
    _waterAmount = 0;
}
Flower::Flower(Color color)
{
    _color = color;
    _waterAmount = 0;
}

std::string Flower::getColor()
{
    if (_color == Color::YELLOW) {
        return "yellow";
    } else if (_color == Color::BLUE) {
        return "blue";
    } else if (_color == Color::ORANGE) {
        return "orange";
    } else {
        return "purple";
    }
}

bool Flower::needsWater()
{
    if (_waterAmount < 5) {
        _ifNeedsWater = true;
    }
    return _ifNeedsWater;
}

void Flower::waterAbsorb(int increaseWaterAmount)
{
    if (needsWater()) {
        _waterAmount += increaseWaterAmount * 0.75;
    }
}

void Flower::checkIfNeedsWater()
{
    if (needsWater()) {
        std::cout << "The " << getColor() << " Flower needs water" << std::endl;
    } else {
        std::cout << "The " << getColor() << " Flower doesn't need water" << std::endl;
    }
}
