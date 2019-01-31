#include <iostream>

// Given base and n that are both 1 or more, compute recursively (no loops)
// the value of base to the n power, so powerN(3, 2) is 9 (3 squared).
int raisingToPower(int base, int exponent)
{
    if (exponent == 0) {
        return 1;
    } else {
        return base * raisingToPower(base, exponent -1);
    }
}

int main()
{   int base, power;
    std::cout << "Give me the base and the power!" << std::endl;
    std::cin >> base >> power;

    std::cout << raisingToPower(base, power);

    return 0;
}