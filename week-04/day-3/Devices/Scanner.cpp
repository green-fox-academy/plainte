#include <iostream>
#include "Scanner.h"

Scanner::Scanner(int speed)
{
    _speed = speed;
}

void Scanner::scan()
{
    std::cout << "I'm scanning a document with " << _speed <<" ppm." << std::endl;
}
