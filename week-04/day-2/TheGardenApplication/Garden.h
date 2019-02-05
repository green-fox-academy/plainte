#ifndef THEGARDENAPPLICATION_GARDEN_H
#define THEGARDENAPPLICATION_GARDEN_H

#include <string>
#include <vector>
#include "Plant.h"
#include "Flower.h"
#include "Tree.h"

class Garden
{
public:
    Garden();
    Garden(std::string name);
    void fillGarden(Color color1, Color color2);
    void waterGarden(double waterBy);
    void checkIfPlantsNeedWater();
private:
    std::vector<Flower> _flowers;
    std::vector<Tree> _trees;
    std::string _name;

};


#endif //THEGARDENAPPLICATION_GARDEN_H
