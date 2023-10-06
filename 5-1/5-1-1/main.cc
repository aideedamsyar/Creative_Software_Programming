#include "shapes.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col; 

    Canvas canvas(row, col);

    string input;
    while (true) {
        cin >> input;
        if (input == "quit") break;

        canvas.Clear();

        int x, y, width, height;
        char brush;

        if (input == "rect") {
            cin >> x >> y >> width >> height >> brush;
            Rectangle* rectangle = new Rectangle(x, y, width, height, brush);
            rectangle->Draw(&canvas);
            cout << "Area: " << rectangle->GetArea() << endl;
            cout << "Perimeter: " << rectangle->GetPerimeter() << endl;
            canvas.Print();
            delete rectangle; 
        }

        if (input == "square") {
            cin >> x >> y >> width >> brush;
            Square* square = new Square(x, y, width, brush);
            square->Draw(&canvas);
            cout << "Area: " << square->GetArea() << endl;
            cout << "Perimeter: " << square->GetPerimeter() << endl;
            canvas.Print();
            delete square; 
        }
    }

    return 0;
}


