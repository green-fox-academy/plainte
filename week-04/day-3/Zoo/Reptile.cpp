#include "Reptile.h"

Reptile::Reptile()
{
    _name = "Reptile";
}

Reptile::Reptile(std::string name) :
    Bird(name)
{

}
