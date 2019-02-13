#ifndef RESTAURANT_EMPLOYEES_H
#define RESTAURANT_EMPLOYEES_H

#include <string>

class Employees
{
public:
    Employees();
    Employees(int experience);
    virtual void work() = 0;
    int getExperience();
protected:
    std::string _name;
    int _experience;

};


#endif //RESTAURANT_EMPLOYEES_H
