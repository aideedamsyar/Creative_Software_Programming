#include "shapes.h"
#include <iostream>
using namespace std;

static char **init(char **matrix, const size_t row, const size_t col) {
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            matrix[i][j] = '.';
    return matrix;
}

static char **auto_alloc(const size_t row, const size_t col) {
    char **matrix = new char*[row];
    
    for (int i = 0; i < row; ++i) matrix[i] = new char[col];

    matrix = init(matrix, row, col);
    
    return matrix;
}

static void auto_delete(char **matrix, const size_t row, const size_t col) {
    for (int i = 0; i < row; ++i) delete[] matrix[i];
    delete[] matrix;
}

void Canvas::Print() const {
    cout << " ";
    for (int i = 0; i < this->col; ++i) cout << (i % 10);
    cout << endl;

    for (int i = 0; i < this->row; ++i) {
        cout << (i % 10);
        for (int j = 0; j < this->col; ++j) cout << this->canvas[i][j];
        cout << endl;}

}

void Canvas::Clear() {
    this->canvas = init(this->canvas, this->row, this->col);
}

// Implement your code
//Canvas
Canvas::Canvas(const size_t row, const size_t col) : row(row), col(col) {
    this->canvas = auto_alloc(row, col);
};

Canvas::~Canvas() {
    auto_delete(this->canvas, this->row, this->col);
};

void Canvas::Resize(const size_t row, const size_t col) {
    auto_delete(this->canvas, this->row, this->col);
    this->row = row;
    this->col = col;
    this->canvas = auto_alloc(this->row, this->col);
}

bool Canvas::DrawPixel(const int x, const int y, const char brush) {
    if (x >= 0 && x < this->col && y >= 0 && y < this->row) {
        this->canvas[y][x] = brush;
        return 1;
    } 
    else { 
        return 0;
    }
}

//Shape
Shape::Shape(const size_t x, const size_t y, const char brush) : x(x), y(y), brush(brush) {}

//Rectangle
Rectangle::Rectangle(const size_t x, const size_t y, const char brush, const size_t width, const size_t height)
: Shape(x, y, brush), width(width), height(height) {}

void Rectangle::Draw(Canvas* canvas) const {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas->DrawPixel(y+i, x+j, brush);
        }
    }
}

void Rectangle::printInfo() const {
    cout << "rect" << " " << x << " " << y << " " << height << " " << width << " " << brush;
}

//UpTriangle
UpTriangle::UpTriangle(const size_t x, const size_t y, const char brush, const size_t height)
: Shape(x, y, brush), height(height) {}

void UpTriangle::Draw(Canvas* canvas) const {
    for (int i = 0; i < height; i++) {
        int d = i;
        for (int j = -d; j <= d; j++){
            canvas->DrawPixel(y+j, x+i, brush);
        }
    }
}

void UpTriangle::printInfo() const {
    cout << "tri_up" << " " << x << " " << y << " " << height << " " << brush;
}

//DownTriangle
DownTriangle::DownTriangle(const size_t x, const size_t y, const char brush, const size_t height)
: Shape(x , y, brush), height(height) {}

void DownTriangle::Draw(Canvas* canvas) const {
    for (int i = 0; i < height; i++) {
        int d = i;
        for (int j = -d; j <= d; j++) {
            canvas->DrawPixel(y-j, x-i, brush);
        }
    }
}

void DownTriangle::printInfo() const {
    cout << "tri_down" << " " << x << " " << y << " " << height << " " << brush;
}

//Diamond
Diamond::Diamond(const size_t x, const size_t y, const char brush, const size_t distance)
: Shape(x, y, brush), distance(distance) {}

void Diamond::Draw(Canvas* canvas) const {
    for (int i = 0; i < distance + 1; i++) {
        int w = i;
        for(int j = -w; j <= w; j++)
            canvas->DrawPixel(y+j, x+i, brush);
    }
    for (int k = 0; k < distance; k++) {
        int w = k;
        for (int l = -w; l <= w; l++) {
            canvas->DrawPixel(y-l, (x + 2*distance) - k, brush);
        }
    }
}

void Diamond::printInfo() const {
    cout << "diamond" << " " << x << " " << y << " " << distance << " " << brush;
}