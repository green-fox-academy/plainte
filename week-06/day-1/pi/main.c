#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

double calculatingArea(double radius);

int main()
{
    // define a variable called PI with the value of 3.14
    // create a function which takes the radius of a circle as a parameter
    // and return the area of that circle
    // area = radius * radius * PI
    double r;
    printf("Please give the radius of your circle!\n");
    scanf("%lf", &r);

    printf("area = %.2lf", calculatingArea(r));

    return 0;
}

double calculatingArea(double radius)
{
    return radius * radius * PI;
}