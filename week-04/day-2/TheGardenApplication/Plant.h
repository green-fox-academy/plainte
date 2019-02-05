#ifndef THEGARDENAPPLICATION_PLANT_H
#define THEGARDENAPPLICATION_PLANT_H

#include <string>

enum Color
{
    YELLOW,
    BLUE,
    PURPLE,
    ORANGE
};

class Plant
{
public:
    Plant();
    Plant(Color color);
    virtual bool ifNeedsWater();
    std::string getColor();
    virtual void waterAbsorb(double increaseWaterByAmount);
    virtual void checkIfNeedsWater();
    double getWaterAmount();
protected:
    Color _color;
    double _waterAmount;
    std::string _name;
};

#endif //THEGARDENAPPLICATION_PLANT_H
