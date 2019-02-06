#include "Printer2D.h"

Printer2D::Printer2D(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}

std::string Printer2D::getSize()
{
    std::string convert;
    return convert = std::to_string(_sizeX) + "X" + std::to_string(_sizeY);
}
