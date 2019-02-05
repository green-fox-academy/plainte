#include <iostream>
#include "Flower.h"

int main(int argc, char * argv[])
{
    Flower yellowFlower(Color::YELLOW);
    yellowFlower.waterAbsorb(10);
    yellowFlower.checkIfNeedsWater();

    Flower blueFlower(Color::BLUE);
    blueFlower.waterAbsorb(20);
    blueFlower.checkIfNeedsWater();

    return 0;
}