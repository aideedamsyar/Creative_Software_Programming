#include "canvas.h"
#include <iostream>

Canvas::Canvas(size_t row, size_t col) : row(row), col(col), vSize(0), vCapacity(10) {
    v = new Shape*[vCapacity];
    canvas = new char*[col];
    for (size_t j = 0; j < col; ++j) {
        canvas[j] = new char[row];
        for (size_t i = 0; i < row; ++i) {
            canvas[j][i] = '.';
        }
    }
}

Canvas::~Canvas() {
    for (size_t i = 0; i < vSize; ++i) {
        delete v[i];
    }
    delete[] v;
    for (size_t j = 0; j < col; ++j) {
        delete[] canvas[j];
    }
    delete[] canvas;
}

void Canvas::Resize(size_t w, size_t h) {
    // 1. assign parameters to member variables
    // 2. deallocate matrix (depth of j since it's 2D)
    // 3. allocate memory for the new matrix with the new size (allocate a 1D array first - use pointer - to the column direction and then loop through each entry and creating another dimension row direction effectively creating a 2D array)
    // 4. initialize with '.'
    this->row = w;
    this->col = h;
    for (size_t j = 0; j < col; ++j) {
        delete[] canvas[j];
    }
    delete[] canvas;

    canvas = new char*[col];
    for (size_t j = 0; j < col; ++j) {
        canvas[j] = new char[row];
        for (size_t i = 0; i < row; ++i) {
            canvas[j][i] = '.';
        }
    }
}

void Canvas::AddShape(Shape* pShape) {
    if (vSize == vCapacity) {
        vCapacity *= 2;
        Shape** newV = new Shape*[vCapacity];
        for (size_t i = 0; i < vSize; i++) {
            newV[i] = v[i];
        }
        delete[] v;
        v = newV;
    }
    v[vSize++] = pShape;
    pShape->Draw(this);
}

void Canvas::DeleteShape(size_t ii) {
    if (ii < 0 || ii >= vSize) return;
    delete v[ii];
    for (size_t i = ii; i < vSize - 1; i++) {
        v[i] = v[i + 1];
    }
    vSize--;
}

bool Canvas::DrawPixel(int x, int y, char brush) {
    if (x < 0 || x >= row || y < 0 || y >= col) return false;
    canvas[y][x] = brush;
    return true;
}

void Canvas::Print() {
    for (size_t j = 0; j < col; ++j) {
        for (size_t i = 0; i < row; ++i) {
            std::cout << canvas[j][i];
        }
        std::cout << std::endl;
    }
}

void Canvas::Clear() {
    for (size_t j = 0; j < col; ++j) {
        for (size_t i = 0; i < row; ++i) {
            canvas[j][i] = '.';
        }
    }
}

void Canvas::PrintShape() {
    for (size_t i = 0; i < vSize; ++i) {
        v[i]->Print();
    }
}

// Implementations for Shape and its derived classes follow...

// ... Remaining code for the shapes ...



// Canvas implementations
//... [Same as before for the Canvas class methods]

// Shape implementations

Shape::Shape() : x(0), y(0), brush('.') {}

Shape::Shape(int x, int y, char brush) : x(x), y(y), brush(brush) {}

Shape::~Shape() {}

void Shape::Draw(Canvas* canvas) {}

void Shape::Print() {
    std::cout << "Shape Info\n";
    std::cout << "X: " << x << ", Y: " << y << ", Brush: " << brush << std::endl;
}

Rectangle::Rectangle(int x, int y, int w, int h, char brush) : Shape(x, y, brush), w(w), h(h) {}

Rectangle::~Rectangle() {}

void Rectangle::Draw(Canvas* canvas) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            canvas->DrawPixel(x+j, y+i, brush);
        }
    }
}

void Rectangle::Print() {
    std::cout << "rect " << x << " " << y << " " << w << " " << h << " " << brush << std::endl;
}

UpTriangle::UpTriangle(int x, int y, int h, char brush) : Shape(x, y, brush), h(h) {}

UpTriangle::~UpTriangle() {}

void UpTriangle::Draw(Canvas* canvas) {
    for (int i = 0; i < h; ++i) {
        for (int j = -i; j <= i; ++j) {
            canvas->DrawPixel(x+j, y+i, brush);
        }
    }
}

void UpTriangle::Print() {
    std::cout << "tri_up " << x << " " << y << " " << h << " " << brush << std::endl;
}

DownTriangle::DownTriangle(int x, int y, int h, char brush) : Shape(x, y, brush), h(h) {}

DownTriangle::~DownTriangle() {}

void DownTriangle::Draw(Canvas* canvas) {
    for (int i = 0; i < h; ++i) {
        for (int j = i-h+1; j < h-i; ++j) {
            canvas->DrawPixel(x+j, y+i, brush);
        }
    }
}

void DownTriangle::Print() {
    std::cout << "tri_down " << x << " " << y << " " << h << " " << brush << std::endl;
}

Diamond::Diamond(int x, int y, int d, char brush) : Shape(x, y, brush), d(d) {}

Diamond::~Diamond() {}

void Diamond::Draw(Canvas* canvas) {
    int h = d/2;
    for (int i = 0; i < h; ++i) {
        for (int j = -i; j <= i; ++j) {
            canvas->DrawPixel(x+j, y+i, brush);
        }
    }
    for (int i = h; i < d; ++i) {
        for (int j = i-d+1; j < d-i; ++j) {
            canvas->DrawPixel(x+j, y+i, brush);
        }
    }
}

void Diamond::Print() {
    std::cout << "diamond " << x << " " << y << " " << d << " " << brush << std::endl;
}
