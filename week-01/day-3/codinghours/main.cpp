#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52
    int a = 17; /* semester */
    int b = 6; /* hours spent coding daily */
    int c = 5; /* weekdays */
    int d = 52; /* working hours weekly */
    int e = a * c * b; /* hours spent coding total */
    float total = a * d; /* total hours of semester */
    float percentage = e / total * 100; /* percentage of coding spent of semester */

    std::cout << "Hours spent coding " << e << std::endl;
    std::cout << "The attendee coding in %" <<  percentage << " of the time" << std::endl;

    return 0;
}