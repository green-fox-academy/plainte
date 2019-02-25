#include <iostream>
#include "Employees.h"
#include "Restaurant.h"

int main()
{
    Restaurant restaurant;

    Chef chef;
    Waiter waiter1;
    Waiter waiter2;
    Waiter waiter3;
    Manager manager;

    restaurant.hire(&chef);
    restaurant.hire(&waiter1);
    restaurant.hire(&waiter2);
    restaurant.hire(&waiter3);
    restaurant.hire(&manager);
    /*for (int i = 0; i < 3; i++) {
        restaurant.guestsArrived();
    } */
    for (unsigned int i = 0; i < restaurant.getEmployees().size(); i++) {
        if (i == restaurant.getEmployees().size() - 1) {
            std::cout << restaurant.getEmployees()[i]->getExperience() << std::endl;
        } else {
            std::cout << restaurant.getEmployees()[i]->getExperience() << " ";
        }
    }
    std::cout << "Testing manager: " << std::endl;
    manager.work();
    std::cout << manager.getMoodLevel() << std::endl;

    for (unsigned int i = 0; i < restaurant.getEmployees().size(); i++) {
        if (i == restaurant.getEmployees().size() - 1) {
            std::cout << restaurant.getEmployees()[i]->getExperience() << std::endl;
        } else {
            std::cout << restaurant.getEmployees()[i]->getExperience() << " ";
        }
    }

    std::vector<int> myVector = {0, 5, 3};

    return 0;
}