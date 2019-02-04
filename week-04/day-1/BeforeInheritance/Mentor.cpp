#include "Mentor.h"

Mentor::Mentor()
{
    name = "Jane Doe";
    age = 30;
    gender = Gender::FEMALE;
    level = Level::INTERMEDIATE;
}

Mentor::Mentor(std::string name_, int age_, Gender gender_, Level level_)
{
    name = name_;
    age = age_;
    gender = gender_;
    level = level_;
}

std::string Mentor::getLevel()
{
    if (level == Level::JUNIOR) {
        return "Junior";
    } else if (level == Level::INTERMEDIATE) {
        return "Intermediate";
    } else {
        return "Senior";
    }
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age << " year old " << getGender() << " "
    << getLevel() << " mentor." << std::endl;
}