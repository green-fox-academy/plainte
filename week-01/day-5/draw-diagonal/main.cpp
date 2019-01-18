#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was
    int a;
    std::cout << "How many lines you want?" << std::endl;
    std::cin >> a;
    int i, j;
    for (i = 0; i < a; i++) {
        for (j = 0; j < a; j++) {
            if (i > 0 && i < (a - 1) && j > 0 && j < (a - 1) && i != j) {
                std::cout << " ";
            } else {
                std::cout << "%";
            }
        }
        std::cout << "\n";
    }
    return 0;
}