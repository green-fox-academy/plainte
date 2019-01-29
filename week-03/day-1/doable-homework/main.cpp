#include <iostream>
#include <string>
#include <map>

int main(int argc, char* args[]) {

    std::map<std::string, std::string> tree01;
    std::map<std::string, std::string> tree02;
    std::map<std::string, std::string> tree03;
    std::map<std::string, std::string> tree04;
    std::map<std::string, std::string> tree05;

    tree01.insert(std::make_pair("type", "Arborvitae"));
    tree01.insert(std::make_pair("leaf color", "ash grey"));
    tree01.insert(std::make_pair("age", "2"));
    tree01.insert(std::make_pair("sex", "female"));

    tree02.insert(std::make_pair("type", "Hawthorn"));
    tree02.insert(std::make_pair("leaf color", "dark brown"));
    tree02.insert(std::make_pair("age", "10"));
    tree02.insert(std::make_pair("sex", "male"));

    tree03.insert(std::make_pair("type", "Pin Cherry"));
    tree03.insert(std::make_pair("leaf color", "reddish brown"));
    tree03.insert(std::make_pair("age", "22"));
    tree03.insert(std::make_pair("sex", "female"));

    tree04.insert(std::make_pair("type", "Butternut"));
    tree04.insert(std::make_pair("leaf color", "light gray"));
    tree04.insert(std::make_pair("age", "5"));
    tree04.insert(std::make_pair("sex", "male"));

    tree05.insert(std::make_pair("type", "American elm"));
    tree05.insert(std::make_pair("leaf color", "dark gray"));
    tree05.insert(std::make_pair("age", "55"));
    tree05.insert(std::make_pair("sex", "male"));


    return 0;
}