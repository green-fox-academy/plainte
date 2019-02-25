#include <stdio.h>
#include <stdlib.h>
#include "circle.h"


int main()
{
    // define a variable called PI with the value of 3.14
    // create a function which takes the radius of a circle as a parameter
    // and return the area of that circle
    // area = radius * radius * PI
    double r;
    printf("Please give the radius of your circle!\n");
    scanf("%lf", &r);

    printf("area = %.2lf\n", calculatingArea(r));
    printf("circumference = %.2lf\n", calculatingCircumference(r));

    return 0;
}