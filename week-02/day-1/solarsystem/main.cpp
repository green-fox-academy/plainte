#include <iostream>
#include <string>
#include <vector>

/* works but complicated
 * std::vector<std::string> putSaturn(const std::vector<std::string>& planets) {
    std::string plus = "Saturn";
    std::vector<std::string> array;
    for(unsigned int i = 0; i < planets.size(); i++) {
        array.push_back(planets[i]);
    }
    array.insert(array.begin() + 5, plus);

    return array;
}
 */
std::vector<std::string> putSaturn(const std::vector<std::string>& planets) {
    std::vector<std::string> array(planets);
    array.insert(array.begin() + 5, "Saturn");
    return array;
}

int main(int argc, char* args[]) {
    std::vector<std::string> planets = {"Mercury","Venus","Earth","Mars","Jupiter","Uranus","Neptune"};

    // Saturn is missing from the planetList
    // Insert it into the correct position
    // Create a method called putSaturn() which has list parameter and returns the correct list.

    // Expected output: Mercury Venus Earth Mars Jupiter Saturn Uranus Neptune
    std::vector<std::string> correctPlanets = putSaturn(planets);

    for(unsigned int i = 0; i < correctPlanets.size(); ++i) {
        std::cout << correctPlanets[i] << " ";
    }

    return 0;
}