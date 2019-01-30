#include "Sharpie.h"


Sharpie::Sharpie(std::string col, float wid, float inkA)
{
    color = col;
    width = wid;
    inkAmount = inkA;
}

void Sharpie::use()
{   if (inkAmount > 0) {
        inkAmount--;
    }
}

void Sharpie::setInkAmount(float x) {
    inkAmount = x;
}

float Sharpie::getInkAmount() {
    return inkAmount;
}