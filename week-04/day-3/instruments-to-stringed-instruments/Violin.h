#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H


#include "StringedInstrument.h"

class Violin : public StringedInstrument
{
public:
    Violin();
    Violin(int numberOfStrings);
    std::string sound() override;
    void play() override;
};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
