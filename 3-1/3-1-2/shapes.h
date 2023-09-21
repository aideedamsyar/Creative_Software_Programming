#ifndef __SHAPES_H__
#define __SHAPES_H__

class Circle {
    public:
        void setInfo(int x, int y, int r);
        double getArea();
        double getPerimeter();

    private:
        int xpos, ypos;
        int radius;
};
    
class Rectangle {
    public:
        void setInfo(int x1, int y1, int x2, int y2);
        double getArea();
        double getPerimeter();

    private:
        int xpos1, ypos1;
        int xpos2, ypos2;
};

#endif // __SHAPE_H__ 