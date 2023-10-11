#include "shapes.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Shape* shape[10];

    char userShape;
    int count = 0;

    while (true) {
        cin >> userShape;
        if (userShape == '0' || count == 10) break;

        double width, height;
        if (userShape == 'r') {
            cin >> width >> height;
            Shape* rectangle = new Rectangle(width, height);
            shape[count] = rectangle;
            count++;
        } else {
            cin >> width >> height;
            Shape* triangle = new Triangle(width, height);
            shape[count] = triangle;
            count++;
        }
    }   

    for (int i=0; i<count; i++) {
        cout << shape[i]->getArea() << endl;
        delete shape[i];
    }
}