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
        double GetArea() {return (x*y); };
        int GetPerimeter() {return (x+x+y+y); };
        void Draw(Canvas *canvas) const {};

    protected: size_t x, y;
        char brush; 
};

// Class Square

class Square : public Shape {
    int width, height;
public: 
    Square(int, int, int, char);
    ~Square();
    void Draw(Canvas*);
    void Print();
    double GetArea() const;      
    int GetPerimeter() const;   
};


// Class Rectangle

class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int, int, int, int, char);
    ~Rectangle();
    void Draw(Canvas*);
    void Print();
    double GetArea() const;      
    int GetPerimeter() const;    
};


#endif //__SHAPE_H__