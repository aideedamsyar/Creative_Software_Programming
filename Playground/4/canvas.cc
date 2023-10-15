#include "canvas.h"
#include <iostream>

//garo width,  row, x, i
//sero height, col, y, j

//canvas[sero][garo]

Canvas::Canvas(size_t row, size_t col) : row(row), col(col) {
    std::vector<char> newRow(row, '.');                 // garo
    canvas.resize(col, newRow);                         // sero
}
Canvas::~Canvas() {
    for (int i = 0; i < v.size(); ++i) {                // shape
        delete v[i];
    }
}
void Canvas::Resize(size_t w, size_t h) {
    this->row = w;                                      // garo
    this->col = h;                                      // sero
    canvas.clear();
    std::vector<char> newRow(row, '.');
    canvas.resize(col, newRow);
}
bool Canvas::DrawPixel(int x, int y, char brush) {      // garo, sero
    if (0 <= x && x < row && 0 <= y && y < col) {       // garo, sero
        canvas[y][x] = brush;                           // sero
        return true;
    }
    return false;
}
void Canvas::Print() {
    Clear();
    for (int i = 0; i < v.size(); ++i) {
        v[i]->Draw(this);
    }
    std::cout << " ";
    for (int i = 0; i < row; ++i) {                     // garo
        std::cout << i % 10;
    }
    std::cout <<"\n";
    for (int j = 0; j < col; ++j) {                     // sero
        std::cout << j % 10;
        for (int i = 0; i < row; ++i) {                 // garo
            std::cout << canvas[j][i];
        }
        std::cout << "\n";
    }
}
void Canvas::Clear() {
    for (int j = 0; j < col; ++j) {                     // sero
        for (int i = 0; i < row; ++i) {                 // garo
            canvas[j][i] = '.';
        }
    }
}
void Canvas::AddShape(Shape* pShape) {
    v.push_back(pShape);
    pShape->Draw(this);
}
void Canvas::DeleteShape(size_t ii) {
    if (ii < 0 || ii >= v.size()) return;               // shape
    delete v[ii];
    v.erase(v.begin() + ii);
}
void Canvas::PrintShape() {
    for (int i = 0; i < v.size(); ++i) {                // shape
        std::cout << i;
        v[i]->Print();
    }
}

Shape::Shape() {}
Shape::Shape(int x, int y, char brush) : x(x), y(y), brush(brush) {}// garo, sero
Shape::~Shape() {}
void Shape::Draw(Canvas* canvas) {}
void Shape::Print() {}

Rectangle::Rectangle (int x, int y, int w, int h, char brush) : Shape(x, y, brush), w(w), h(h) {}
Rectangle::~Rectangle() {};
void Rectangle::Draw(Canvas* pCanvas) {
    for (int j = y; j < y + h; ++j) {                   // sero
        for (int i = x; i < x + w; ++i) {               // garo
            pCanvas->DrawPixel(i, j, brush);            // garo, sero
        }
    }
}
void Rectangle::Print() {
    std::cout << " rect " << x << " " << y << " " << w << " " << h << " " << brush << "\n";
}

UpTriangle::UpTriangle(int x, int y, int h, char brush) : Shape(x, y, brush), h(h) {}
UpTriangle::~UpTriangle() {}
void UpTriangle::Draw(Canvas* pCanvas) {
    int cnt = 0;
    for (int j = y; j < y + h; ++j) {                   // sero
        for (int i = x - cnt; i <= x + cnt; ++i) {      // garo
            pCanvas->DrawPixel(i, j, brush);            // garo, sero
        }
        ++cnt;
    }
}
void UpTriangle::Print() {
    std::cout << " tri_up " << x << " " << y << " " << h << " " << brush << "\n";
}

DownTriangle::DownTriangle(int x, int y, int h, char brush) : Shape(x, y, brush), h(h) {}
DownTriangle::~DownTriangle() {}
void DownTriangle::Draw(Canvas* pCanvas) {
    int cnt = 0;
    for (int j = y; j > y - h; --j) {
        for (int i = x - cnt; i <= x + cnt; ++i) {
            pCanvas->DrawPixel(i, j, brush);
        }
        ++cnt;
    }
}
void DownTriangle::Print() {
    std::cout << " tri_down " << x << " " << y << " " << h << " " << brush << "\n";
}
Diamond::Diamond(int x, int y, int d, char brush) : Shape(x, y, brush), d(d) {}
Diamond::~Diamond() {}
void Diamond::Draw(Canvas* pCanvas) {
    int cnt = 0;
    for (int j = y; j < y + d - 1; ++j) {
        for (int i = x - cnt; i <= x + cnt; ++i) {
            pCanvas->DrawPixel(i, j, brush);
        }
        ++cnt;
    }
    for (int j = y + d - 1; cnt >= 0; ++j) {
        for (int i = x - cnt; i <= x + cnt; ++i) {
            pCanvas->DrawPixel(i, j, brush);
        }
        --cnt;
    }
}
void Diamond::Print() {
    std::cout << " diamond " << x << " " << y << " " << d << " " << brush << "\n";
}