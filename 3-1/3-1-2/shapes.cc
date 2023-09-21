#include "shapes.h"
#include <cmath>

//Circle class
void Circle::setInfo(int x, int y, int r) {
    xpos = x;
    ypos = y;
    radius = r;
}

double Circle::getArea() {
    return 3.14 * radius * radius;
}

double Circle::getPerimeter() {
    return 3.14 * (2 * radius);
}

//Rectangle class
void Rectangle::setInfo(int x1, int y1, int x2, int y2) {
    xpos1 = x1;
    ypos1 = y1;
    xpos2 = x2;
    ypos2 = y2;
}

double Rectangle::getArea() {
    return sqrt(pow((ypos2 - ypos1) * (xpos2 - xpos1),2)); 
}

double Rectangle::getPerimeter() {
    return 2 * (sqrt(pow(ypos2 - ypos1, 2)) + sqrt(pow((xpos2 - xpos1), 2)));
}