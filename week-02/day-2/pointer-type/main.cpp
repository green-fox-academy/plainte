#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *p_a = nullptr;
    double *p_b = nullptr;
    std::string *p_name = nullptr;

    p_a = &a;
    p_b = &b;
    p_name = &name;

    std::cout << p_a << " " << p_b << " " << p_name << " " << std::endl;
    std::cout << *p_a << " " << *p_b << " " << *p_name << std::endl;

    return 0;
}