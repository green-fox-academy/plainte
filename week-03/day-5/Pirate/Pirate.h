#ifndef PIRATE_PIRATE_H
#define PIRATE_PIRATE_H
#include <string>
#include "PirateNames.h"
#include <iostream>

class Pirate
{
public:
    Pirate();
    Pirate(std::string& _pirateName, int& _drunkLevel);
    void drinkSomeRum();
    void howItsGoingMate();
    bool isAliveAndAwake();
    void die();
    void passOut();
    int getDrunkLevel();
    void brawl(Pirate &otherPirate);
    std::string getPirateName();
    std::string hadParrot();
private:
    std::string pirateName;
    int drunkLevel;
    bool isPassedOut = false;
    bool isDead = false;
    bool gotParrot;
    std::string GetNameForPirates();

};


#endif
