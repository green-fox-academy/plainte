#ifndef PETROL_STATION_CAR_H
#define PETROL_STATION_CAR_H


class Car
{
public:
    Car(int carGasAmount,int carCapacity);
    int gasAmount, capacity;

    bool isFull();
    void fill();
};


#endif //PETROL_STATION_CAR_H
