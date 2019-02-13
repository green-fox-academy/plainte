#ifndef RESTAURANT_CHEF_H
#define RESTAURANT_CHEF_H


#include "Employees.h"
#include <vector>


class Chef : public Employees
{
public:
    Chef();
    Chef(int experience);
    void work() override;
    void cook(std::string meal);
private:
    std::vector<std::pair<std::string, int>> _meals;
};


#endif //RESTAURANT_CHEF_H
