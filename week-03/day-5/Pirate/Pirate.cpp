#include "Pirate.h"


Pirate::Pirate() //default constructor with random names and 0 drunk Level
{
    pirateName = GetNameForPirates();
    drunkLevel = 0;
    gotParrot = rand() % 2; //random generating parrot if 0 hasn't got if 1 has;
}
Pirate::Pirate(std::string& _pirateName, int& _drunkLevel) //constructor when creating with specified values
{
    pirateName = _pirateName;
    drunkLevel = _drunkLevel;
    gotParrot = rand() % 2; //don't have to specify it when creating Pirate
}
void Pirate::drinkSomeRum() //simply checks if alive and awake then increments the value of drunk Level
{
    if(isAliveAndAwake()) {
        drunkLevel++;
    }
}
void Pirate::howItsGoingMate() //if the pirate drunk level is lower than 4 then he gets another beer else passes out
{   if (isAliveAndAwake()) { //call the is alive and awake function to check if dead or passed out or alive - if then goes into if
        if (drunkLevel < 4) {
            drinkSomeRum();
            std::cout << "Pour me anudder!" << std::endl;
        } else {
            std::cout << "Arghh, I'ma Pirate. How d'ya d'ink its goin?" << std::endl;
            passOut();
        }
    }
}

std::string Pirate::GetNameForPirates() //get random name for pirates created by default constructor from 'pirateNames.h'
{
    int size = sizeof(pirateNames) / sizeof(pirateNames[0]);
    int i = rand() % size;
    return pirateNames[i];
}

void Pirate::passOut() //pirate passes out
{
    isPassedOut = true;
}

void Pirate::die() //pirate dies
{
    isDead = true;
}

bool Pirate::isAliveAndAwake() //check if the pirate is dead or passed out - else awake and alive
{
    if (isDead) {
        std::cout << "He's dead!" << std::endl;
        return false;
    } else if (isPassedOut) {
        std::cout << pirateName << " is passed out"  << std::endl;
        return false;
    } else {
        return true;
    }
}

int Pirate::getDrunkLevel() //getting drunk level
{
    return drunkLevel;
}

void Pirate::brawl(Pirate &otherPirate) //2 pirates fighting
{
    if (otherPirate.isAliveAndAwake()) {
        int chance = rand() % 3; // 1/3 chance
        if (chance == 0) { //1st case - 1st die 2nd won
            die();
            std::cout << otherPirate.getPirateName() << " won!" << std::endl;
            std::cout << getPirateName() << " died!" << hadParrot() << std::endl;
        } else if (chance == 1) { //2nd case - 2nd die 1st won
            otherPirate.die();
            std::cout << getPirateName() << " won!" << std::endl;
            std::cout << otherPirate.getPirateName() << " died!" << hadParrot() << std::endl;
        } else { //3rd case both pass out
            passOut();
            otherPirate.passOut();
            std::cout << getPirateName() << " and " << otherPirate.getPirateName() << " passed out!" << std::endl;
        }
    }
}

std::string Pirate::getPirateName() //gets Pirate name
{
    return pirateName;
}

std::string Pirate::hadParrot()
{
    if (gotParrot) {
        return " His/her parrot needs a new owner!";
    } else {
        return " He/she hasn't got a parrot!";
    }
}
