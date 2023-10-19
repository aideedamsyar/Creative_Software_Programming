#include "classes.h"
#include <iostream>

using namespace std;

int main() {
    A* objArr[3];

    objArr[0] = new A();
    objArr[1] = new B();
    objArr[2] = new C();

    for (int i=0; i<3; i++) {
        objArr[i]->test();
        delete objArr[i];
    }

    return 0;
}