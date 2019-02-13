#include "Manager.h"

Manager::Manager() : Employees()
{
    _moodLevel = 400;
}

Manager::Manager(int experience) : Employees(experience)
{
    _moodLevel = 400;
}

void Manager::work()
{
    _experience++;
    haveAMeeting();
}

void Manager::haveAMeeting()
{
    _moodLevel -= _experience;
}

int Manager::getMoodLevel()
{
    return _moodLevel;
}
