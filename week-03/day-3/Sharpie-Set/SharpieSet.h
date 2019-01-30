#include "Sharpie.h"

#ifndef SHARPIE_SET_SHARPIESET_H
#define SHARPIE_SET_SHARPIESET_H

#include <vector>

class SharpieSet {
public:
    SharpieSet(std::vector<Sharpie> x);


    std::vector<Sharpie> ob;
    int countUsable();
    void removeTrash();

};


#endif //SHARPIE_SET_SHARPIESET_H
