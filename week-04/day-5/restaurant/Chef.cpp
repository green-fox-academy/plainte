
#include "Chef.h"

Chef::Chef() : Employees()
{
}

Chef::Chef(int experience) : Employees(experience)
{
}

void Chef::work()
{
    _experience++;
}

void Chef::cook(std::string meal)
{
    for(unsigned int i = 0; i < _meals.size(); i++) {
        if (meal == _meals[i].first) {
            _meals[i].second++;
        } else {
            _meals.emplace_back(make_pair(meal, 1));
        }
    }
}
