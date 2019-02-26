#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
    enum car_type type;
    double km;
    double gas;
};

void print_car_details(struct car c);

int main()
{
    struct car car1;
    car1.type = VOLVO;
    car1.gas = 5.24;
    car1.km = 23125.5;
    struct car car2;
    car2.type = TESLA;
    car2.km = 10123.66;
    struct car car3;
    car3.type = TOYOTA;
    car3.gas = 21.11;
    car3.km = 2312.42;
    struct car car4;
    car4.type = LAND_ROVER;
    car4.gas = 1.6;
    car4.km = 123125123.2;
    print_car_details(car3);
    print_car_details(car4);
    print_car_details(car1);
    print_car_details(car2);
    return 0;
}

void print_car_details(struct car c)
{
    if (c.type == VOLVO) {
        printf("The VOLVO:\n\t- %.2lf km\n\t- %.2lf gas\n", c.km, c.gas);
    } else if (c.type == TOYOTA) {
        printf("The TOYOTA:\n\t- %.2lf km\n\t- %.2lf gas\n", c.km, c.gas);
    } else if (c.type == LAND_ROVER) {
        printf("The LAND_ROVER:\n\t- %.2lf km\n\t- %.2lf gas\n", c.km, c.gas);
    } else if (c.type == TESLA) {
        printf("The TESLA:\n\t- %.2lf km\n\t- is electric\n", c.km);
    }
}