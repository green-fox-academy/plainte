#include <string>

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie
{
public:
    Sharpie(std::string col, float wid, float inkA);
    void use();
    void setInkAmount(float x);
    float getInkAmount();
    std::string color;
    float width;
private:
    float inkAmount;
};


#endif //SHARPIE_SHARPIE_H
