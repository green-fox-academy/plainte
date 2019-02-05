#include <iostream>
#include "Tree.h"

Tree::Tree()
{
    _name = "Tree";
}

Tree::Tree(Color color) :
    Plant(color)
{
    _name = "Tree";
}

bool Tree::ifNeedsWater()
{
    return _waterAmount < 10;
}

void Tree::waterAbsorb(double increaseWaterByAmount)
{
    if (ifNeedsWater()) {
        _waterAmount += increaseWaterByAmount * 0.4;
    }
}

void Tree::checkIfNeedsWater()
{
    if (ifNeedsWater()) {
        std::cout << "The " << getColor() << " " << _name << " needs water" << std::endl;
    } else {
        std::cout << "The " << getColor() << " " << _name << " doesnt need water" << std::endl;
    }
}
