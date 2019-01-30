#include "car.h"

Car::Car(int carGasAmount, int carCapacity)
{
    gasAmount = carGasAmount;
    capacity = carCapacity;
}

bool Car::isFull()
{
    if (capacity == gasAmount) {
        return  true;
    } else {
        return  false;
    }
}

void Car::fill()
{
    gasAmount++;
}

