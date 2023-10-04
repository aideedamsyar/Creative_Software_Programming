#ifndef __SHAPE_H__ 
#define __SHAPE_H__

#include <cmath>

class Canvas { 
    public:
        Canvas(const size_t row, const size_t col); 
        ~Canvas();
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
        double GetArea() {};
        int GetPerimeter() {};
        void Draw(Canvas *canvas) const {};
        protected: size_t x, y;
        char brush; 
};
// Class Square
// Class Rectangle

#endif //__SHAPE_H__