#ifndef RESTAURANT_RESTAURANT_H
#define RESTAURANT_RESTAURANT_H

#include "Employees.h"
#include "Chef.h"
#include "Manager.h"
#include "Waiter.h"

#include <string>
#include <vector>

class Restaurant
{
public:
    Restaurant();
    Restaurant(const std::string& name, const int& foundationDate);
    void guestsArrived();
    void hire(Employees* employee);
    std::vector<Employees*> getEmployees();
private:
    std::string _name;
    int _foundationDate;
    std::vector<Employees*> _employees;

};


#endif //RESTAURANT_RESTAURANT_H
