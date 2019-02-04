#ifndef BEFOREINHERITANCE_STUDENT_H
#define BEFOREINHERITANCE_STUDENT_H
#include <iostream>
#include "Person.h"

class Student : public Person
{
public:
    Student();
    Student(std::string name_, int age_, Gender gender_, std::string previousOrg);
    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);
protected:
    std::string previousOrganization;
    int skippedDays;
};


#endif