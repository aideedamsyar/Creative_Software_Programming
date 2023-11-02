#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <iostream>
#include <vector>

class Shape {
    public:
        Shape();
        Shape(double width, double height);
        virtual ~Shape() {};
        virtual double getArea() = 0;
    protected:
        double width;
        double height;
};

class Triangle : public Shape {
    public:
        Triangle(double width, double height);
        ~Triangle();
        double getArea();  
        
};

class Rectangle : public Shape {
    public:
        Rectangle(double width, double height);
        ~Rectangle();
        double getArea();
};

#endif //__SHAPES_H_