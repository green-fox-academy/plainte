#include <iostream>
#include <string>

std::string appendAFunc(std::string a){
    std::string b = "a";
    a += b;
    return a;
}
int main(int argc, char* args[]) {

    // - Create a string variable named `typo` and assign the value `Chinchill` to it
    // - Write a function called `appendAFunc` that gets a string as an input,
    //   appends an 'a' character to its end and returns with a string
    //
    // - Print the result of `appendAFunc(typo)`
    std::string typo = "Chinchill";

    appendAFunc(typo);

    std::cout << appendAFunc(typo) << std::endl;

    return 0;
}