#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one
    int a, b;
    std::cout << "Give me two numbers" << std::endl;
    std::cin >> a >> b;
    if (a > b) {
        std::cout << "The bigger number is: " << a << std::endl;
    } else {
        std::cout << "The bigger number is: " << b << std::endl;
    }
    return 0;
}