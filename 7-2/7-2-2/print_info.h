#ifndef __PRINT_INFO_H__
#define __PRINT_INFO_H__
#include <string>
using namespace std;

class A {
    public:
        virtual string getTypeInfo();
};

class B : public A {
    public:
        string getTypeInfo();
};

class C : public B {
    public:
        string getTypeInfo();
};


#endif //__PRINT_INFO_H__