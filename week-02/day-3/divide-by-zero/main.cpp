#include <iostream>
#include <fstream>

int main() {
    try {
        int a = 10;
        int b;
        std::cout << "Give me a number" << std::endl;
        std::cin >> b;

        if (b == 0) {
            throw 0;
        } else {
            std::cout << a / b << std::endl;
        }
    } catch (int b) {
        std::cout << "fail";
    }
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    return 0;
}