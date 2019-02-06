#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H


#include "StringedInstrument.h"

class BassGuitar  : public StringedInstrument
{
public:
    BassGuitar();
    BassGuitar(int numberOfStrings);
    std::string sound() override;
    void play() override;
};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
