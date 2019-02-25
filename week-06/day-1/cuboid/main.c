#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    // Surface Area: 600
    // Volume: 1000

    double a, b, c;
    printf("Give me the sides of your cuboid!\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    double area = 2 * ((a + b) + (a + c) + (b + c));
    double volume = a * b * c;

    printf("Surface Area: %.2lf\n", area);
    printf("Volume: %.2lf\n", volume);

    return 0;
}