#ifndef GF_INHERITANCE_EXERCISE_SPONSOR_H
#define GF_INHERITANCE_EXERCISE_SPONSOR_H

#include "Person.h"

class Sponsor : public Person
{
public:
    Sponsor();
    Sponsor(std::string name, int age, Gender gender, std::string company);
    void introduce() override;
    void hire();
    void getGoal() override;
private:
    std::string _company;
    int _hiredStudents;
};


#endif //GF_INHERITANCE_EXERCISE_SPONSOR_H
