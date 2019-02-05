#ifndef BEFOREINHERITANCE_MENTOR_H
#define BEFOREINHERITANCE_MENTOR_H
#include <iostream>
#include "Person.h"

enum Level
{
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person
{
public:
    Mentor();
    Mentor(std::string name_, int age_, Gender gender_, Level level_);
    std::string getLevel();
    void getGoal() override;
    void introduce() override;
protected:
    Level level;
};

#endif