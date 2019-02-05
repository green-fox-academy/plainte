#ifndef GF_INHERITANCE_EXERCISE_STUDENT_H
#define GF_INHERITANCE_EXERCISE_STUDENT_H

#include "Person.h"

class Student : public Person
{
public:
    Student();
    Student(std::string name, int age, Gender gender, std::string previousOrganization);
    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);
private:
    std::string _previousOrganization;
    int _skippedDays;
};


#endif //GF_INHERITANCE_EXERCISE_STUDENT_H
