#include <iostream>
using namespace std;

void rotateLeft(int* pa, int* pb, int* pc){
    int temp = *pa;
    *pa = *pb;
    *pb = *pc;
    *pc = temp;
}

void rotateRight(int* pa, int* pb, int*pc){
    int temp = *pc;
    *pc = *pb;
    *pb = *pa;
    *pa = temp;
}

int main(void){
    int a=10, b=20, c=30;
    char input;
    cout << a << ':' << b << ':' << c << endl;

    while (true) {
        cin >> input;
        if (input == 'L') {
        rotateLeft(&a, &b, &c);
        cout << a << ':' << b << ':' << c << endl;
        }   else if (input == 'R') {
        rotateRight(&a, &b, &c);
        cout << a << ':' << b << ':' << c << endl;
        }   else if (input == 'E') {
            break;
        }   else {
        cout << "Error: Wrong input!" << endl;
            break;
        }
    }
    return 0;
}
