#include <iostream>

int main(int argc, char* args[]) {

    // Define several things as a variable then print their values
    // Your name as a string
    // Your age as an integer
    // Your height in meters as a double
    // Whether you are married or not as a boolean
    std::string myname = "Dani";
    int myage = 22;
    double myheight = 1.79;
    bool married = false;

    std::cout << "My name is " << myname << std::endl;
    std::cout << "My age is " << myage << std::endl;
    std::cout << "My height in double is " << myheight << std::endl;
    std::cout << "Marital status (0-not married, 1-married) " << married << std::endl;


    return 0;
}