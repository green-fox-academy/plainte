#include "Mammal.h"

Mammal::Mammal()
{
    _name = "Mammal";
}

Mammal::Mammal(std::string name) :
    Bird(name)
{

}

std::string Mammal::breed()
{
    return "pushing miniature versions out.";
}
