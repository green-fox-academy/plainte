#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.
    int i = 1;
    while(i < 101) {
        if((i % 3 == 0) && (i % 5 != 0)) {
            std::cout << "Fizz" << std::endl;
        }
        else if((i % 5 == 0) && (i % 3 != 0)) {
            std::cout << "Buzz" << std::endl;
        }
        else if((i % 3 == 0) && (i % 5 == 0)) {
            std::cout << "FizzBuzz" << std::endl;
        }
        if((i % 3 != 0) && (i % 5 != 0)){
            std::cout << i << std::endl;
        }
        i++;
    }
    return 0;
}