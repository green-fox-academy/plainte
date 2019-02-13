#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant()
{
    _name = "Brew’d Awakening Coffeehaus";
    _foundationDate = 1996;
}

Restaurant::Restaurant(const std::string& name,const int& foundationDate)
{
    _name = name;
    _foundationDate = foundationDate;
}

void Restaurant::guestsArrived()
{
    for (unsigned int i = 0; i < _employees.size(); i++) {
        _employees[i]->work();
    }
}

void Restaurant::hire(Employees* employee)
{
    _employees.push_back(employee);
}

std::vector<Employees*> Restaurant::getEmployees()
{
    return _employees;
}


