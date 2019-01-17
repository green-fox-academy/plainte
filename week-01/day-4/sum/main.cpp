#include <iostream>
#include <string>

int sum(int a){
    int b = 0;
    for(int i = 0; i <= a; i++){
        b += i;
    }
    return b;
}
int main(int argc, char* args[]) {

    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer
    int y;
    std::cout << "Give me a number" << std::endl;
    std::cin >> y;

    std::cout << "The sum of these numbers is " << sum(y) << std::endl;


    return 0;
}