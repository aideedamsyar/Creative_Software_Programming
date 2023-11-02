#include "shapes.h"
#include <vector>
using namespace std;

Shape::Shape() {}
Shape::Shape(double width, double height) : width(width), height(height) {}


Triangle::Triangle(double width, double height) : Shape(width, height) {}
Triangle::~Triangle() {}

double Triangle::getArea() {
    return (width*height)/2;
}

Rectangle::Rectangle(double width, double height) : Shape(width,height) {}
Rectangle::~Rectangle() {}

double Rectangle::getArea() {
    return (width*height);
}

