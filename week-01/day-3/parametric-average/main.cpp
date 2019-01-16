#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4
    int num;
    int a;
    double sum;
    std::cout << "Give me a number!" << std::endl;
    std::cin >> num;
    for(int i = 0; i < num; i++){
        std::cout << "Please give an integer!" << std::endl;
        std::cin >> a;
        sum += a;
    }
    double average = sum / num;

    std::cout << "Sum: " << sum << ", Average: " << average << std::endl;

    return 0;
}