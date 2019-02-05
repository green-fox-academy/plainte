#include "Garden.h"
#include <iostream>

Garden::Garden()
{
    _name = "My first virtual garden";
}

Garden::Garden(std::string name)
{
    _name = name;
}

void Garden::fillGarden(Color color1, Color color2)
{
    _flowers.push_back(Flower(color1));
    _trees.push_back(Tree(color2));
}

void Garden::waterGarden(double waterBy)
{
    std::cout << "Watering with " << waterBy << std::endl;
    int totalPlants = ifTreesNeedWater();

    for (int j = 0; j < _flowers.size(); j++) {
        _flowers[j].waterAbsorb(waterBy / totalPlants);
    }
    for (int i = 0; i < _trees.size(); i++) {
        _trees[i].waterAbsorb(waterBy / totalPlants);
    }
}

void Garden::checkIfPlantsNeedWater()
{
    for (int j = 0; j < _flowers.size(); j++) {
        _flowers[j].checkIfNeedsWater();
    }
    for (int i = 0; i < _trees.size(); i++) {
        _trees[i].checkIfNeedsWater();
    }
}

int Garden::ifTreesNeedWater()
{   _howManyPlantNeedsWater = 0;
    for (int i = 0; i < _trees.size(); i++) {
        if (_trees[i].ifNeedsWater()) {
            _howManyPlantNeedsWater++;
        }
    }
    for (int j = 0; j < _flowers.size(); j++) {
        if (_flowers[j].ifNeedsWater()) {
            _howManyPlantNeedsWater++;
        }
    }
    return _howManyPlantNeedsWater;
}
