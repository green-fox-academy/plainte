#include <iostream>
#include "Helicopter.h"
int main(int argc, char * argv[])
{
    Helicopter helicopter("OH-58D", "Kiowa", "Bell");
    helicopter.takeOff();
    helicopter.fly();
    helicopter.land();

    Helicopter copter;
    copter.takeOff();
    copter.fly();
    copter.land();

    return 0;
}