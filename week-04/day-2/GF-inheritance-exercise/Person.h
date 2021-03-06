#ifndef GF_INHERITANCE_EXERCISE_PERSON_H
#define GF_INHERITANCE_EXERCISE_PERSON_H

#include <string>

enum Gender
{
    MALE,
    FEMALE,
    OTHER
};

class Person
{
public:
    Person();
    Person(std::string name, int age, Gender gender);
    virtual void introduce();
    virtual void getGoal();
    std::string getGender();
protected:
    std::string _name;
    int _age;
    Gender _gender;
};


#endif //GF_INHERITANCE_EXERCISE_PERSON_H
