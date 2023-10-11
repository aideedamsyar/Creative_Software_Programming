#include "animal.h"
#include <iostream>
#include <string>
using namespace std;

Animal::Animal(string _name, int _age) {
    this->name = _name;
    this->age = _age;
}

Animal::~Animal() {}

Zebra::Zebra(string name, int age, int _numOfStripe) : Animal(name, age), numOfStripe(_numOfStripe) {}
Zebra::~Zebra() {}

Cat::Cat(string name, int age, string _favToy) : Animal(name, age), favToy(_favToy) {}
Cat::~Cat() {}

void Zebra::printInfo() {
    cout << "Zebra, Name: " << this->name << ", Age: " << this->age << ", Number of stripes: " << this->numOfStripe << endl;
}

void Cat::printInfo() {
    cout << "Cat, Name: " << this->name << ", Age: " << this->age << ", Favorite toy: " << this->favToy << endl;
}