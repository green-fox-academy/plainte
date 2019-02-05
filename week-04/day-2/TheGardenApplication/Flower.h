#ifndef THEGARDENAPPLICATION_FLOWER_H
#define THEGARDENAPPLICATION_FLOWER_H

#include <string>

enum Color
{
    YELLOW,
    BLUE,
    PURPLE,
    ORANGE
};

class Flower
{
public:
    Flower();
    Flower(Color color);
    virtual bool needsWater();
    std::string getColor();
    virtual void waterAbsorb(int increaseWaterAmount);
    virtual void checkIfNeedsWater();
protected:
    Color _color;
    double _waterAmount;
    bool _ifNeedsWater = false;
};


#endif //THEGARDENAPPLICATION_FLOWER_H
