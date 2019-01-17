#include <iostream>
#include <string>

int factorio(int y, int s){
    int factorial;
    for(int i = 0; i <= y; i++){
         factorial *= i;
    }
    factorial = s;
    return factorial;
}

int main(int argc, char* args[]) {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.
    int a;
    std::cout << "Give me a number!" << std::endl;
    std::cin >> a;
    int b;
    std::cout << "Give me a new number!" << std::endl;
    std::cin >> b;

    factorio(a, b);

    std::cout << "The number is: " << factorio(a, b) << std::endl;

    return 0;
}