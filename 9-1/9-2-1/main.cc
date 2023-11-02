#include "shapes.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<Shape*> shapes;

    double width; 
    double height;

    cin >> width >> height;
    Shape* triangle = new Triangle(width, height);
    shapes.push_back(triangle);

    cin >> width >> height;
    Shape* rectangle = new Rectangle(width, height);
    shapes.push_back(rectangle);

    for (int i=0; i<2; i++) {
        cout << shapes[i]->getArea() << endl;
        delete shapes[i];
    }

    return 0;
}