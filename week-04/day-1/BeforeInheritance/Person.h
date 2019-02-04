#ifndef BEFOREINHERITANCE_PERSON_H
#define BEFOREINHERITANCE_PERSON_H
#include <string>

enum class Gender
{
    MALE,
    FEMALE
};

class Person
{
public:
    Person();
    Person(std::string name_, int age_, Gender gender_);
    virtual void introduce();
    virtual void getGoal();
    std::string getGender();
protected:
    std::string name;
    int age;
    Gender gender;
};

#endif
