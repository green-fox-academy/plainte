#include <iostream>

// We have bunnies standing in a line, numbered 1, 2, ... The odd bunnies
// (1, 3, ..) have the normal 2 ears. The even bunnies (2, 4, ..) we'll say
// have 3 ears, because they each have a raised foot. Recursively return the
// number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).
int calculateTheEars(int a)
{   int ears = 2;
    if (a == 0) {
        return 0;
    } else if (a % 2 == 1) {
        return calculateTheEars(a - 1) + ears;
    } else {
        ears = 3;
        return calculateTheEars(a - 1) + ears;
    }
}
int main()
{
    try {
        int bunnies;
        std::cout << "How many bunnies we have in the line?" << std::endl;
        std::cin >> bunnies;
        if (bunnies < 0) {
            throw -1;
        } else {
            std::cout << calculateTheEars(bunnies);
        }
    } catch (...) {
    std::cout << "The minimum number of bunnies is 0!" << std::endl;
    }
    return 0;
}