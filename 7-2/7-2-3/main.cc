#include "print_member.h"
#include <iostream>
#include <string>

int main() {
    int integ;
    double doub;
    string str;

    cin >> integ >> doub >> str;

    A* objArr[3];
    objArr[0] = new A(integ);
    objArr[1] = new B(doub);
    objArr[2] = new C(str);


    for (int i=0; i<3; i++) {
        objArr[i]->print();
    }

    for (int i=0; i<3; i++) {
        delete objArr[i];
    }
    

    return 0;
}