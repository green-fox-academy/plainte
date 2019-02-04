#include "Student.h"
#include <iostream>

Student::Student()
{
    name = "Jane Doe";
    age = 30;
    gender = Gender::FEMALE;
    previousOrganization = "The School of Life";
    skippedDays = 0;
}

Student::Student(std::string name_, int age_, Gender gender_, std::string previousOrg)
{
    name = name_;
    age = age_;
    gender = gender_;
    previousOrganization = previousOrg;
    skippedDays = 0;
}
void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age << " year old " << getGender() << " from " << previousOrganization
    << " who skipped " << skippedDays << " days from the course already." << std::endl;
}

void Student::skipDays(int numberOfDays)
{
    skippedDays += numberOfDays;
}