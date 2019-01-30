#include "SharpieSet.h"
#include "Sharpie.h"
#include <iostream>
#include <vector>

SharpieSet::SharpieSet(std::vector<Sharpie> x)
{
    ob = x;
}

int SharpieSet::countUsable()
{
    int temp = 0;
    for (unsigned int i = 0; i < ob.size(); i++) {
        if (ob[i].getInkAmount() > 0) {
             temp++;
        }
    }
    return temp;
}

void SharpieSet::removeTrash() {
    for (int i = 0; i < ob.size(); i++) {
        if (ob[i].getInkAmount() == 0) {
            ob.erase(ob.begin() + i);
            i--;
        }
    }
}
