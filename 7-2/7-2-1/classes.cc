#include "classes.h"
#include <iostream>
using namespace std;

A::~A() {}

void A::test() {
    cout << "A::test()" << endl;
}

void B::test() {
    cout << "B::test()" << endl;
}

void C::test() {
    cout << "C::test()" << endl;
}
