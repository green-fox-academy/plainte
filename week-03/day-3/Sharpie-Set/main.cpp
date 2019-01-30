#include <iostream>
#include "Sharpie.h"
#include <string>
#include "SharpieSet.h"
#include <vector>

int main(int argc, char * argv[])
{
    Sharpie object("blue", 10.5, 0); //Sharpie 1
    Sharpie object2("green", 9.2, 45); //Sharpie 2
    Sharpie object3("pink", 11.9, 20); //Sharpie 3
    Sharpie object4("yellow", 5.2, 38); //Sharpie 4


    int decrease;
    std::cout << "Tell me how much would you like to decrease the inkAmount: ";
    std::cin >> decrease;
    for (int i = 0; i < decrease; i++) {
        object.use();
        object2.use();
        object3.use();
        object4.use();
    }
    std::vector<Sharpie> myVector; //created  vector containing Sharpie named myVector and filled
    myVector.push_back(object);
    myVector.push_back(object2);
    myVector.push_back(object3);
    myVector.push_back(object4);
    SharpieSet set(myVector); //SharpieSet object created

    std::cout << object.getInkAmount() << std::endl; //testing outputs
    std::cout << object2.getInkAmount() << std::endl;
    std::cout << object3.getInkAmount() << std::endl;
    std::cout << object4.getInkAmount() << std::endl;

    set.removeTrash(); //remove unusable sharpies

    std::cout << set.countUsable(); // remaining/usable sharpies


    return 0;
}