#ifndef ZOO_MAMMAL_H
#define ZOO_MAMMAL_H


#include "Bird.h"

class Mammal : public Bird
{
public:
    Mammal();
    Mammal(std::string name);
    std::string breed() override;
};


#endif //ZOO_MAMMAL_H
