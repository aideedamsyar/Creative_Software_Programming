#include "canvas.h"
#include <string>
#include <iostream>
int main() {
    int r, c;
    std::cin >> r >> c; // cin >> width >> height
    Canvas canvas(r,c);
    canvas.Print();
    std::string q;
    while (std::cin >> q && q != "quit") {
        if (q == "add") {
            std::string shape;
            std::cin >> shape;
            int x, y, w, h;
            char brush;
            if (shape == "rect") {
                std::cin >> x >> y >> w >> h >> brush;
                Rectangle* rectangle = new Rectangle(x, y, w, h, brush);
                canvas.AddShape(rectangle);
            }
            else {
                std::cin >> x >> y >> h >> brush;
            }
            if (shape == "tri_up") {
                UpTriangle* ut = new UpTriangle(x, y, h, brush);
                canvas.AddShape(ut);
            }
            else if (shape == "tri_down") {
                DownTriangle* dt = new DownTriangle(x, y, h, brush);
                canvas.AddShape(dt);
            }
            else if (shape == "diamond") {
                Diamond* diamond = new Diamond(x, y, h, brush);
                canvas.AddShape(diamond);
            }
        }
        else if (q == "delete") {
            size_t shape;
            std::cin >> shape;
            canvas.DeleteShape(shape);
        }
        else if (q == "draw") {
            canvas.Print();
        }
        else if (q == "dump") {
            canvas.PrintShape();
        }
        else if (q == "resize") {
            size_t newWidth, newHeight;
            std::cin >> newWidth >> newHeight;
            canvas.Resize(newWidth, newHeight);
        }

    }
    return 0;
}