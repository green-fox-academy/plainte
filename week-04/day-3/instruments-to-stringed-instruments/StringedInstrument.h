#ifndef INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H


#include "Instrument.h"

class StringedInstrument : public Instrument
{
public:
    virtual std::string sound() = 0;
protected:
    int _numberOfStrings;
};


#endif //INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
