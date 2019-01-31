#include <iostream>

// We have a number of bunnies and each bunny has two big floppy ears.
// We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).
int getTheEars(int x, int y)
{
    if (x == 0) {
        return 0;
    } else if (x == 1) {
        return y;
    } else {
        return getTheEars(x - 1, y) + y;
    }
}

int main()
{   int bunnies;
    std::cout << "How many bunnies we have?" << std::endl;
    std::cin >> bunnies;
    int ears;
    std::cout << "How many floppy ears a bunny has?" << std::endl;
    std::cin >> ears;

    std::cout << getTheEars(bunnies, ears);
    return 0;
}