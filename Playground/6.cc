#include <iostream> 
using namespace std; 

class test {
       float x, y;
    public:
    test(float a = 1.0, float b = 2.0) 
    {
        x = a;
        y = b;
    }
    test operator + (test & obj) {
        return test(this->x + obj.x, y + obj.y); 
    }
    
    operator float () {
        return(x + y) ;
       }
};

int main () {
    test obj1(1.23, 4.56), obj2; 
    obj2 = obj1 + obj2;
    cout << obj2;
    return 0;
}
