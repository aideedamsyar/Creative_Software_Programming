#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>
using namespace std;

class Animal {
    public:
        Animal(string _name, int _age);
        virtual ~Animal();
        virtual void printInfo() = 0; // pure virtual function
    protected:
        string name;
        int age;
};

// Class Zebra
class Zebra : public Animal {
    public:
        Zebra(string, int, int);
        ~Zebra();
        void printInfo();
    private:
        int numOfStripe;
};

// Class Cat
class Cat : public Animal {
    public:
        Cat(string, int, string);
        ~Cat();
        void printInfo();
    private:
        string favToy;
};


#endif // __ANIMAL_H__