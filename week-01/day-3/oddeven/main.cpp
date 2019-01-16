#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.
    int num;
    std::cout << "Give me a number!" << std::endl;
    std::cin >> num;
    if (num % 1 == 0) {
        std::cout << "The number is even!" << std::endl;
    } else {
        std::cout << "The number is odd!" << std::endl;;
    }

    return 0;
}