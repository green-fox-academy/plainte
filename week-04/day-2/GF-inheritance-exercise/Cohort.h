#ifndef GF_INHERITANCE_EXERCISE_COHORT_H
#define GF_INHERITANCE_EXERCISE_COHORT_H

#include <string>
#include <vector>
#include "Student.h"
#include "Mentor.h"

class Cohort
{
public:
    Cohort(std::string name);
    void addStudent(Student*);
    void addMentor(Mentor*);
    void info();
    int getStudentSize();
    int getMentorSize();
private:
    std::string _name;
    std::vector<Student> _students;
    std::vector<Mentor> _mentors;


};


#endif //GF_INHERITANCE_EXERCISE_COHORT_H
