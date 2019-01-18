#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;
    int hours = 24;
    int minutes = 60;
    int seconds = minutes;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables
    int total = seconds * minutes * hours;
    int currentTotal = currentHours * minutes * seconds + currentMinutes * seconds + currentSeconds;
    int remaining = total - currentTotal;

    std::cout << "The remaining second of today is: " << remaining << std::endl;

    return 0;
}