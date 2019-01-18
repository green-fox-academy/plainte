#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    int a;
    double sum = 0;
    int n;
    std::cout << "How many integers you want?" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Give me a new integer!" << std::endl;
        std::cin >> a;
        sum += a;
    }
    double average = sum / n;
    std::cout << "The sum is " << sum << std::endl;
    std::cout << "The average is " << average << std::endl;

    return 0;
}