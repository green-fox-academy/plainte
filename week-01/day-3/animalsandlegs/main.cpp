#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have
    int a;
    int b;
    std::cout << "How many chickens you have?" << std::endl;
    std::cin >> a;
    std::cout << "How many pigs you have?" << std::endl;
    std::cin >> b;
    int total = a * 2 + b * 4;

    std::cout << "The animals you have has " << total << " legs!" << std::endl;

    return 0;
}