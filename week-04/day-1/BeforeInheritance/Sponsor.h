#ifndef BEFOREINHERITANCE_SPONSOR_H
#define BEFOREINHERITANCE_SPONSOR_H
#include "Person.h"

class Sponsor : public Person
{
public:
    Sponsor();
    Sponsor(std::string name_, int age_, Gender gender_, std::string company_);
    void introduce() override;
    void hire();
    void getGoal() override;
protected:
    std::string company;
    int hiredStudents;
};


#endif
