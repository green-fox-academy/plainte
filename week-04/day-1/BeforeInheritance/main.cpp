#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Mentor.h"
#include "Sponsor.h"

int main(int argc, char * argv[])
{
    std::vector<Person*> people;

    Person* mark = new Person("Mark", 46, Gender::MALE);
    people.push_back(mark);
    Person* jane = new Person();
    people.push_back(jane);
    Student* john = new Student("John Doe", 20, Gender::MALE, "BME");
    people.push_back(john);
    Student* student = new Student();
    people.push_back(student);
    Mentor* gandhi = new Mentor("Gandhi", 148, Gender::MALE, Level::SENIOR);
    people.push_back(gandhi);
    Mentor* mentor = new Mentor();
    people.push_back(mentor);
    Sponsor* sponsor = new Sponsor();
    people.push_back(sponsor);
    Sponsor* elon = new Sponsor("Elon Musk", 46, Gender::MALE, "SpaceX");
    people.push_back(elon);

    student->skipDays(3);

    for (int i = 0; i < 5; i++) {
        elon->hire();
    }

    for (int i = 0; i < 3; i++) {
        sponsor->hire();
    }

    for(Person* person : people) {
        person->introduce();
        person->getGoal();
    }

    for(Person* person : people)
    {
        delete person;
    }

    return 0;
}