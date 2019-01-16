#include <iostream>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;

    // Print the Body mass index (BMI) based on these values
    double height = heightInM * heightInM;
    double BMI = massInKg / height;

    std::cout << BMI << std::endl;

    return 0;
}