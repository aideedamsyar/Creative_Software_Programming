#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <cmath>

class Canvas {
    public:
        Canvas(const size_t row, const size_t col);
        ~Canvas();
        void Resize (const size_t row, const size_t col);
        bool DrawPixel(const int x, const int y, const char brush);
        void Print() const;
        void Clear();
    private:
        size_t row, col;
        char **canvas;
};

class Shape {
    public:
        Shape();
        Shape(const size_t x, const size_t y, const char brush);
        virtual ~Shape() {}
        virtual void Draw(Canvas *canvas) const = 0;
        virtual void printInfo() const = 0;
    protected:
        size_t x, y;
        char brush;
};

// ClassRectangle
class Rectangle : public Shape {
    public: 
        Rectangle();
        Rectangle(const size_t x, const size_t y, const char brush, const size_t width, const size_t height);
        void Draw(Canvas* canvas) const;
        void printInfo() const;

    private:
        size_t width, height;
};

// Class UpTriangle
class UpTriangle : public Shape {
    public:
        UpTriangle(); 
        UpTriangle(const size_t x, const size_t y, const char brush, const size_t height);
        void Draw(Canvas* canvas) const;
        void printInfo() const;

    private:
        size_t height;
};

// Class DownTriangle
class DownTriangle : public Shape {
    public: 
        DownTriangle();
        DownTriangle(const size_t x, const size_t y, const char brush, const size_t height);
        void Draw(Canvas* canvas) const;
        void printInfo() const;

    private:
        size_t height;  
};

// Class Diamond
class Diamond : public Shape {
    public: 
        Diamond();
        Diamond(const size_t x, const size_t y, const char brush, const size_t distance);
        void Draw(Canvas* canvas) const;
        void printInfo() const;

    private:
        size_t distance;
};

#endif //__SHAPE_H__