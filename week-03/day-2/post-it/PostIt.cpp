#include <iostream>
#include "PostIt.h"

PostIt::PostIt(std::string x, std::string j, std::string p) {
    backGroundColor = x;
    text = j;
    textColor = p;
}