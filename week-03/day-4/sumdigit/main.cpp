#include <iostream>

// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
int sumOfDigits(int n)
{
    if (n < 10){
        return n;
    } else {
        return n % 10 + sumOfDigits(n / 10);
    }
}
int main()
{
    int n;
    std::cout << "Give a non-negative integer!" << std::endl;
    std::cin >> n;

    std::cout << sumOfDigits(n) << std::endl;

    return 0;
}