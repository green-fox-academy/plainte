#include "myApplesClass.h"

std::string getApple()
{
    return "apple";
}

int sum(std::vector<int> elements)
{
    int total = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        total += elements[i];
    }
    return total;
}
