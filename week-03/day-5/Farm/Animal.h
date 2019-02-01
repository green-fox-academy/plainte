#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H


class Animal
{
public:
    Animal();

    void setHunger(int hunger_);
    void setThirst(int thirst_);
    int getHunger();
    int getThirst();
    void eat();
    void drink();
    void play();
private:
    int hunger, thirst;
};


#endif //ANIMAL_ANIMAL_H