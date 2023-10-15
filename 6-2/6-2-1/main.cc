#include "shapes.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int maxShapes = 10; 
    Shape* shapes[maxShapes];
    int count = 0;
    string action;
    size_t x, y, row, col;
    char brush;

    cin >> col >> row;

    Canvas* canvas = new Canvas(row, col);

    canvas->Clear();
    canvas->Print();

    while (true) {
        cin >> action;

        if (action == "quit" || count == maxShapes) { break; }

        if (action == "add") {
            string shape;
            cin >> shape >> x >> y;
            if (shape == "rect") {
                size_t width, height;

                cin >> width >> height >> brush;

                if (count < maxShapes) {
                    shapes[count] = new Rectangle(x, y, brush, height, width);
                    shapes[count]->Draw(canvas);
                    count++;
                }
            }
            else if (shape == "tri_up") {
                size_t height;

                cin >> height >> brush;

                if (count < maxShapes) {
                    shapes[count] = new UpTriangle(x, y, brush, height);
                    shapes[count]->Draw(canvas);
                    count++;
                }
            }
            else if (shape == "tri_down") {
                size_t height;

                cin >> height >> brush;

                if (count < maxShapes) {
                    shapes[count] = new DownTriangle(x, y, brush, height);
                    shapes[count]->Draw(canvas);
                    count++;
                }
            }
            else if (shape == "diamond") {
                size_t distance;

                cin >> distance >> brush;

                if (count < maxShapes) {
                    shapes[count] = new Diamond(x, y, brush, distance);
                    shapes[count]->Draw(canvas);
                    count++;
                }
            }
        }
        else if (action == "delete") {
            int removeIndex;
            cin >> removeIndex;

            if (removeIndex >= 0 && removeIndex < count) {
                delete shapes[removeIndex];
                for (int i = removeIndex; i < count - 1; i++) {
                    shapes[i] = shapes[i + 1];
                }
                count--;

                canvas->Clear();
                for (int i = 0; i < count; i++) {
                    shapes[i]->Draw(canvas);
                }
            }
        }
        else if (action == "dump") {
            for (int i = 0; i < count; i++) {
                cout << i << " ";
                shapes[i]->printInfo();
                cout << endl;
            }
        }
        else if (action == "resize") {
            cin >> col >> row;
            canvas->Resize(row, col);

            for (int i = 0; i < count; i++) {
                shapes[i]->Draw(canvas);
            }
        }
        else if (action == "draw") {
            canvas->Clear();
            for (int i = 0; i < count; i++) {
                shapes[i]->Draw(canvas);
            }
            canvas->Print();
        }
    }

    // Clean up allocated memory
    for (int i = 0; i < count; i++) {
        delete shapes[i];
    }
    delete canvas;

    return 0;
}
