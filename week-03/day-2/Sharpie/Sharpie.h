#include <string>

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie
{
public:
    Sharpie(std::string col, float wid);

    std::string color;
    float width, inkAmount;

    void use();
};


#endif //SHARPIE_SHARPIE_H
