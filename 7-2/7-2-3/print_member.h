#ifndef __PRINT_MEMBER_H__
#define __PRINT_MEMBER_H__

#include <string>

using namespace std;

class A {
    public:
        A(int);
        virtual ~A();
        virtual void print();
    private:
        int* memberA;
};

class B : public A {
    public:
        B(double);
        ~B();
        void print();;
    private:
        double* memberB;
};

class C : public B {
    public:
        C(string);
        ~C();
        void print();
    private:
        string* memberC;
};


#endif //__PRINT_MEMBER_H__