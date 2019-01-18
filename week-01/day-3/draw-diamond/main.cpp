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
    int n, y, i, space;
    std::cout << "Enter number of rows!" << std::endl;
    std::cin >> n;
    space = n - 1;

    for (i = 1; i <= n; i++) {
        for (y = 1; y <= space; y++) {
            std::cout << " ";
        }
        space--;
        for (y = 1; y <= 2 * i - 1; y++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    space = 1;
    for (i = 1; i <= n; i++) {
        for (y = 1; y <= space; y++) {
            std::cout << " ";
        }
        space++;
        for (y = 1; y <= 2 * (n - i) - 1; y++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}