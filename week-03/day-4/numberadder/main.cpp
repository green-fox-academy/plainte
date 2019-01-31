#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.
int add(int n)
{
    if (n == 1) {
        return n;
    } else {
        return  add(n-1) + n;
    }
}

int main() {
    try {
        int n;
        std::cout << "Give me a positive integer! (for instance 0 is not valid)" << std::endl;
        std::cin >> n;

        if (n < 1) {
            throw 0;
        } else {
            std::cout << add(n) << std::endl;
        }
    } catch (...) {
        std::cout << "Not a valid positive integer" << std::endl;
    }
    return 0;
}