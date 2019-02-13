#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H


#include "Employees.h"

class Manager : public Employees
{
public:
    Manager();
    Manager(int experience);
    void work() override;
    void haveAMeeting();
    int getMoodLevel();
private:
    int _moodLevel;
};


#endif //RESTAURANT_MANAGER_H
