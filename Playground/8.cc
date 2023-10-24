#include <iostream>
using namespace std;
namespace first
{
    int x = 5;
    int y = 10; 
}

namespace second

{
    double x = 3.1416; 
    double y = 2.7183;
}

int main ()
{
    using first::x;
    using second::y;
    bool a, b;
    a = x > y;
    b = first::y < second::x,
    cout << a << b;
    return 0; 
}