#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    double a;
    double b;
    double c;

    std::cout << "Give me a!" << std::endl;
    std::cin >> a;
    std::cout << "Give me b!" << std::endl;
    std::cin >> b;
    std::cout << "Give me c!" << std::endl;
    std::cin >> c;

    double surface = 2 * (a * b +  a * c + b * c);
    std::cout << "The surface are is: " << surface << std::endl;
    double volume = a * b * c;
    std::cout << "The volume of the cuboid is: " << volume << std::endl;

    return 0;
}