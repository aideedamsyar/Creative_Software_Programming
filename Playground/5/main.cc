#include "shapes.h"
#include <iostream>
#include <string>

using namespace std;

void updateIndex(Shape** shapes, int* shapeCount, int* index) {
    if (*index >= 0 && *index < *shapeCount) {
        delete shapes[*index];
        for (int i = *index; i < *shapeCount - 1; i++) {
            shapes[i] = shapes[i + 1];
        }
        (*shapeCount)--;
    }
}

int main(void) {
    Shape* shapes[10];
    string action;
    size_t x, y, row, col;
    char brush;
    int index = 0;;

    cin >> col >> row;

    Canvas* canvas = new Canvas(row, col);

    canvas->Clear();
    canvas->Print();

    while (1) {
        string type;

        cin >> action;

        if (action == "add") {
            cin >> type >> x >> y ;
            if (type == "rect") {
                size_t width, height;

                cin >> width >> height >> brush; 

                shapes[index] = new Rectangle(x, y, brush, height, width);
                shapes[index]->Draw(canvas);

                index++;
            }
            else if (type == "tri_up") {
                size_t height;

                cin >> height >> brush;

                shapes[index] = new UpTriangle(x, y, brush, height);
                shapes[index]->Draw(canvas);

                index++;
            }
            else if (type == "tri_down") {
                size_t height;

                cin >> height >> brush;

                shapes[index] = new DownTriangle(x, y, brush, height);
                shapes[index]->Draw(canvas);
                
                index++;
            }
            else if (type == "diamond") {
                size_t distance;

                cin >> distance >> brush;

                shapes[index] = new Diamond(x, y, brush, distance);
                shapes[index]->Draw(canvas);

                index++;
            }
        }
        else if (action == "delete") {
            int removeIndex;

            cin >> removeIndex;

            updateIndex(shapes, &index, &removeIndex);
            canvas->Clear();

            for (int i = 0; i < index; i++) {
                shapes[i]->Draw(canvas);
            }
        }
        else if (action == "dump") {

            for (int i = 0; i < index; i++) {
                cout << i << " ";
                shapes[i]->printInfo();
                cout << endl;
            }
        }
        else if (action == "resize") {
            cin >> col >> row;
            canvas->Resize(row, col);

            for (int i = 0; i < index; i++) {
                shapes[i]->Draw(canvas);
            }
        }
        else if (action == "draw") {
            canvas->Clear();
            for (int i = 0; i < index; i++) {
                shapes[i]->Draw(canvas);
            }
            canvas->Print();
        }
        else if (action == "quit") {
            break;
        }
    }

    return 0;
}