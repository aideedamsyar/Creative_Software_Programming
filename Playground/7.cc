# include <iostream> 
using namespace std; 

class x {
    public:
        int a;
        x();
};

x::x() { a=10; cout<<a; }

class b: public x {
    public: 
        b();
};

b::b() { a=20; cout<<a; }

int main() {
    b temp; return 0;
}

