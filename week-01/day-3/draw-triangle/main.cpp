#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // triangle like this:
    //
    // *
    // **
    // ***
    // ****
    //
    // The triangle should have as many lines as the number was
    int n;
    std::cout << "How many lines you want?" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}