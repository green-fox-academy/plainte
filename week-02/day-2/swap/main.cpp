#include <iostream>

void swap(int *p_a, int *p_b) {
    int temp = 0;
    temp = *p_a;
    *p_a = *p_b;    
    *p_b = temp;
}

int main ()
{
    // Create a function which swaps the values of 'a' and 'b'
    // This time use a void funtion and pointers

    int a = 10;
    int b = 316;

    int *p_a = &a;
    int *p_b = &b;

    swap(p_a, p_b);

    std::cout << a << " " << b << std::endl;

    return 0;
}