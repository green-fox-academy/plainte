#ifndef THEGARDENAPPLICATION_FLOWER_H
#define THEGARDENAPPLICATION_FLOWER_H

#include "Plant.h"
#include <string>

class Flower : public Plant
{
public:
    Flower();
    Flower(Color color);
    bool ifNeedsWater() override;
    void waterAbsorb(double increaseWaterByAmount) override;
    void checkIfNeedsWater() override;
};


#endif //THEGARDENAPPLICATION_FLOWER_H
