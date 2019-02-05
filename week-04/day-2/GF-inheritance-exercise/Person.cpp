#include "Person.h"
#include <iostream>

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
}

Person::Person(std::string name, int age, Gender gender)
{
    _name = name;
    _age = age;
    _gender = gender;
}

std::string Person::getGender()
{
    if (_gender == Gender::FEMALE) {
        return "female";
    } else if (_gender == Gender::MALE) {
        return "male";
    } else {
        return "other";
    }
}

void Person::introduce()
{
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << getGender() << "." << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!" << std::endl;
}