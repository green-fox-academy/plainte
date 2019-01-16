#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it
    int km;
    double miles;

    std::cout << "Give me a distance!" << std::endl;
    std::cin >> km;
    miles = km * 0.62137;
    std::cout << "The distance given in km is " << miles << "in miles!" << std::endl;


    return 0;
}