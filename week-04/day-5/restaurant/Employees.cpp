#include "Employees.h"

Employees::Employees()
{
    _experience = 0;
}

Employees::Employees(int experience)
{
    _experience = experience;
}

int Employees::getExperience()
{
    return _experience;
}
