#include "shapes.h"
#include <iostream>
#include <cstring>
using namespace std;

int main(void){
    Circle circle;
    Rectangle rectangle;

    char shape;

    int n1, n2, n3, n4;

    while(1){
        cout << "shape?" << endl;
        cin >> shape;

        if (shape == 'C') {
            cin >> n1 >> n2 >> n3;

            circle.setInfo(n1, n2, n3);
            cout << "area: " << circle.getArea() << ", perimeter: "<< circle.getPerimeter() << endl;
        }
        else if (shape == 'R') {
            cin >> n1 >> n2 >> n3 >> n4;

            rectangle.setInfo(n1, n2, n3, n4);
            cout << "area: " << rectangle.getArea() << ", perimeter: " << rectangle.getPerimeter() << endl; 
        }
        else if (shape == 'Q'){
            break;
        }
    }

    return 0;
}