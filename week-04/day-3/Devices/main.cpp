#include <iostream>
#include <vector>
#include "Printer.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Scanner.h"
#include "Copier.h"


int main( int argc, char* args[] )
{
    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    // Create a Copier object and invoke copy function on it.
    std::vector<Printer*> printer;

    Printer2D first2D(1, 2);
    Printer2D second2D(2, 1);
    Printer2D third2D(5, 5);

    Printer3D first3D(3, 5, 2);
    Printer3D second3D(5, 2, 6);

    Copier copier(2, 5, 10);

    printer.push_back(&first2D);
    printer.push_back(&second2D);
    printer.push_back(&third2D);
    printer.push_back(&first3D);
    printer.push_back(&second3D);
    printer.push_back(&copier);

    for (int i = 0; i < printer.size(); i++) {
        printer[i]->print();
    }

    std::vector<Scanner*> scanner;

    Scanner firstScanner(10);
    Scanner secondScanner(20);

    Copier firstCopier(3, 4, 15);
    Copier secondCopier(4, 8, 40);

    scanner.push_back(&firstScanner);
    scanner.push_back(&secondScanner);
    scanner.push_back(&firstCopier);
    scanner.push_back(&secondCopier);

    for (int i = 0; i < scanner.size(); i++) {
        scanner[i]->scan();
    }

    Copier testCopier(5, 10, 60);

    testCopier.copy();

    return 0;
}