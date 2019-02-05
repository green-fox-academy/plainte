#ifndef THEGARDENAPPLICATION_TREE_H
#define THEGARDENAPPLICATION_TREE_H

#include "Plant.h"

class Tree : public Plant
{
public:
    Tree();
    Tree(Color color);
    bool ifNeedsWater() override;
    void waterAbsorb(double increaseWaterByAmount) override;
    void checkIfNeedsWater() override;
};


#endif //THEGARDENAPPLICATION_TREE_H
