#include "shapes.h"

Shape::Shape(double width, double height) {
    this->width = width;
    this->height = height;
}

Shape::~Shape() {}

Rectangle::Rectangle(double width, double height) : Shape(width, height) {}
Rectangle::~Rectangle() {}
double Rectangle::getArea() {
    return this->width * this->height;
}

Triangle::Triangle(double width, double height) : Shape(width, height) {}
Triangle::~Triangle() {}
double Triangle::getArea() {
    return (this->width * this->height)/2;
}