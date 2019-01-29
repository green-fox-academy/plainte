#include "Sharpie.h"


Sharpie::Sharpie(std::string col, float wid)
{
    color = col;
    width = wid;
    inkAmount = 100;
}

void Sharpie::use()
{
    inkAmount--;
}