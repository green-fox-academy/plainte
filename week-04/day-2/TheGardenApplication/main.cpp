#include <iostream>
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"
#include "Garden.h"

int main(int argc, char * argv[])
{
    Garden firstGarden("kert");
    firstGarden.fillGarden(Color::YELLOW, Color::PURPLE);
    firstGarden.fillGarden(Color::BLUE, Color::ORANGE);

    firstGarden.checkIfPlantsNeedWater();

    firstGarden.waterGarden(40);
    firstGarden.checkIfPlantsNeedWater();

    firstGarden.waterGarden(70);
    firstGarden.checkIfPlantsNeedWater();

    return 0;
}