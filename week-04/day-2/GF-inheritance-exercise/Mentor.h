#ifndef GF_INHERITANCE_EXERCISE_MENTOR_H
#define GF_INHERITANCE_EXERCISE_MENTOR_H

#include "Person.h"

enum Level
{
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person
{
public:
    Mentor();
    Mentor(std::string name, int age, Gender gender, Level level);
    void getGoal() override;
    void introduce() override;
    std::string getLevel();
private:
    Level _level;
};


#endif //GF_INHERITANCE_EXERCISE_MENTOR_H
