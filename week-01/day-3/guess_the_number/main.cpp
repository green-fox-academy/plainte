#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8
    int num = 8;
    int a;
    while(a != num) {
        std::cout << "Guess the number!" << std::endl;
        std::cin >> a;
        if (a < num) {
            std::cout << "The number is higher" << std::endl;
        } else if (a > num) {
            std::cout << "The number is lower" << std::endl;
        } else {
            std::cout << "You found the number: 8" << std::endl;
        }
    }
    return 0;
}