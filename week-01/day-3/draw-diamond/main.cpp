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
    // only works with 7
    std::cin >> n;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < (n + 1) / 2 - i - 1; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    if (n % 2 == 0) {
        n -= 1;
    }
    for (int i = (n - 1) / 2 - 1; i >= 0; i--) {
        for (int j = 0; j <= n / 2 - i - 1; j++) {
            std::cout << " ";
        }
        for (int j = 0 ; j < 2 * i + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}