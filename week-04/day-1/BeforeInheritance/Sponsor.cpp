#include "Sponsor.h"
#include <iostream>

Sponsor::Sponsor()
{
    name = "Jane Doe";
    age = 30;
    gender = Gender::FEMALE;
    company = "Google";
    hiredStudents = 0;
}

Sponsor::Sponsor(std::string name_, int age_, Gender gender_, std::string company_)
{
    name = name_;
    age = age_;
    gender = gender_;
    company = company_;
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age << " year old " << getGender() <<
    " who represents " << company << " and hired " << hiredStudents << " students so far." << std::endl;
}

void Sponsor::hire()
{
    hiredStudents++;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}