#include <iostream>
using namespace std;
int sub1(int &n)
{
    n--;    return n;
}

int main()
{
    int m = 10;
    for(int j = 0; j < 10; j++) 
        m -= sub1(j);
       cout << m << "\n";
return 0; 
}