#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // Create a program that writes this line 100 times:
    // "I won't cheat on the exam!"
    for( int i = 0; i < 100; i++){
        std::cout << i << " I won't cheat on the exam!" << std::endl;
    }
    /* or
    int i = 0;
    while(i < 100) {
        std::cout << i << " I won't cheat on the exam!\n";
        i++;
    } */

    return 0;
}