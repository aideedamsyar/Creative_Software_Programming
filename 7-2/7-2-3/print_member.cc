#include "print_member.h"
#include <iostream>
using namespace std;

A::A(int integer) : memberA(new int(integer)) {
    cout << "new memberA" << endl;
}

A::~A() {
    delete memberA;
    cout << "delete memberA" << endl;
}

B::B(double doub) : A(1), memberB(new double(doub)) {
    cout << "new memberB" << endl;
}

B::~B() {
    delete memberB;
    cout << "delete memberB" << endl;
}

C::C(string str) : B(1.1), memberC(new string(str)) {
    cout << "new memberC" << endl;
}

C::~C() {
    delete memberC;
    cout << "delete memberC" << endl;
}

void A::print() {
    cout << "*memberA " << *memberA << endl;
}

void B::print() {
    A::print();
    cout << "*memberB " << *memberB << endl;
}

void C::print() {
    B::print();
    cout << "*memberC " << *memberC << endl;
}