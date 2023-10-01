#include "zebra.h"
#include <iostream>
using namespace std;

Zebra::Zebra() {
    name = "";
    age = 0;
    numStripes = 0;
}

Zebra::Zebra(string _name, int _age, int _numStripes) {
    this -> name = _name;
    this -> age = _age;
    this -> numStripes = _numStripes;
}

void Zebra::printZebra() {
    std::cout << "Name: " << this->name << ", Age: " << this->age << ", Number of stripes: " << this->numStripes << endl;
}