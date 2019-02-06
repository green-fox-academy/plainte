#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H


#include "Vehicle.h"
#include "Flyable.h"

class Helicopter : public Vehicle, public Flyable
{
public:
    Helicopter();
    Helicopter(std::string type, std::string model, std::string manufacturer);
    void land() override;
    void fly() override;
    void takeOff() override;
};


#endif //FLYABLE_HELICOPTER_H
