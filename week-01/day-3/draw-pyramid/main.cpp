#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        //for loop for displaying space
        for (int y = i; y < n; y++) {
            std::cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}