#include "print_info.h"
#include <iostream>

void printObjectTypeInfo1(A* object) {
    cout << object->getTypeInfo() << endl;
}

void printObjectTypeInfo2(A& object) {
    cout << object.getTypeInfo() << endl;
}


int main() {
    A* objArr[3];

    objArr[0] = new A();
    objArr[1] = new B();
    objArr[2] = new C();

    for (int i=0; i<3; i++) {
        printObjectTypeInfo1(objArr[i]);
        printObjectTypeInfo2(*objArr[i]);
        delete objArr[i];
    }

    return 0;
}