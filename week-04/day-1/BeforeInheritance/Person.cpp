#include "Person.h"
#include <iostream>

Person::Person()
{
    name = "Jane Doe";
    age = 30;
    gender = Gender::FEMALE;
}

std::string Person::getGender()
{
    if (gender == Gender::FEMALE) {
        return "Female";
    } else {
        return "Male";
    }
}

Person::Person(std::string name_, int age_, Gender gender_)
{
    name = name_;
    age = age_;
    gender = gender_;
}
void Person::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age << " year old " << getGender() << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}