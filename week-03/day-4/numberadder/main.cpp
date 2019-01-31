#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.
int add(int n)
{
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
}

int main() {
    try {
        int n;
        std::cout << "Give me a positive integer! (for instance 0 is not valid)" << std::endl;
        std::cin >> n;
        if (n <= 0) {
            throw 0;
        } else {
            std::cout << add(n) << std::endl;
        }
    } catch(int x) {
        std::cout << "Not a (valid) positive integer!" << std::endl;
    }

    return 0;
}