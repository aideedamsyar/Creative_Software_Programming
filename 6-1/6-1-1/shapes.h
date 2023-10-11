#ifndef __SHAPE_H__
#define __SHAPE_H__

class Shape {
    public:
        Shape(double width, double height);
        virtual ~Shape();
        virtual double getArea() = 0; // pure virtual function
    protected:
        double width, height;
};

// Class Triangle
class Triangle : public Shape {
    public:
    Triangle(double, double);
    ~Triangle();
    double getArea();
};

// Class Rectangle
class Rectangle : public Shape {
    public:
    Rectangle(double, double);
    ~Rectangle();
    double getArea();
};

#endif //__SHAPE_H__