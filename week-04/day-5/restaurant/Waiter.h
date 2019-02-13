#ifndef RESTAURANT_WAITER_H
#define RESTAURANT_WAITER_H


#include "Employees.h"

class Waiter : public Employees
{
public:
    Waiter();
    Waiter(int experience);
    void work() override;
private:
    int _tips;
};


#endif //RESTAURANT_WAITER_H
