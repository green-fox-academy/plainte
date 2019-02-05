#include <iostream>
#include "Cohort.h"

Cohort::Cohort(std::string name)
{   _name = name;
    _students.clear();
    _mentors.clear();
}

void Cohort::addStudent(Student *)
{
    _students.emplace_back(Student());
}

void Cohort::addMentor(Mentor *)
{
    _mentors.emplace_back(Mentor());
}

void Cohort::info()
{
    std::cout << "The " << _name << " cohort has " << _students.size() << " students and "
    << _mentors.size() << " mentors." << std::endl;
}

