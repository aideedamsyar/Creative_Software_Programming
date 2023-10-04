#ifndef __CANVAS_H__
#define __CANVAS_H__
#include <cstddef>

class Shape;

class Canvas {
public:
    Canvas(size_t row, size_t col);
    ~Canvas();
    void Resize(size_t w, size_t h);
    bool DrawPixel(int x, int y, char brush);
    void Print();
    void Clear();
    void AddShape(Shape*);
    void DeleteShape(size_t);
    void PrintShape();
private:
    size_t row, col;
    size_t vSize, vCapacity;
    Shape** v;
    char** canvas;
};

class Shape {
public:
    Shape();
    Shape(int, int, char);
    virtual ~Shape();
    virtual void Draw(Canvas* canvas);
    virtual void Print();
protected:
    int x, y;
    char brush;
};

class Rectangle : public Shape {
    int w, h;
public:
    Rectangle(int, int, int, int, char);
    ~Rectangle();
    void Draw(Canvas*);
    void Print();
};

class UpTriangle : public Shape {
    int h;
public:
    UpTriangle(int, int, int, char);
    ~UpTriangle();
    void Draw(Canvas*);
    void Print();
};

class DownTriangle : public Shape {
    int h;
public:
    DownTriangle(int, int, int, char);
    ~DownTriangle();
    void Draw(Canvas*);
    void Print();
};

class Diamond : public Shape {
    int d;
public:
    Diamond(int, int, int, char);
    ~Diamond();
    void Draw(Canvas*);
    void Print();
};

#endif
