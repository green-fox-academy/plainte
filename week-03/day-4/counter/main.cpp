#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.
int count(int n)
{
    if (n <= 1) {
        std::cout <<"Number: " << n << std::endl;
        return 1;
    } else {
        std::cout <<"Number: " << n << std::endl;
        return count(n-1);
    }
}

int main() {
    int n;
    std::cout << "Give me an integer!" << std::endl;
    std::cin >> n;

    count(n);

    return 0;
}