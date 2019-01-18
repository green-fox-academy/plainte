#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was
    int n;
    std::cout << "How many lines you want?" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n / 2 + 1; i++) {
        for (int j = i; j < n; j++) {
            std::cout << " ";
        }
        for (int j = 0; j <= (2 * i); j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    for (int i = n / 2 + 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << "%";
        }
        std::cout << "\n";
    }

    return 0;
}