#include <iostream>

using namespace std;

typedef struct
{
    int xpos;
    int ypos;
} Point;

Point getScalePoint(Point* p, int s){
    Point temp;
    temp.xpos = p->xpos*s;
    temp.ypos = p->ypos*s;
    return temp;
}

void swapPoints(Point* p1, Point* p2){
    Point temp;
    temp.xpos = p1->xpos;
    temp.ypos = p1->ypos;
    p1->xpos = p2->xpos;
    p1->ypos = p2->ypos;
    p2->xpos = temp.xpos;
    p2->ypos = temp.ypos;
}

int main(void){
    Point p1, p2;
    int scalep1, scalep2;
    
    cin >> p1.xpos >> p1.ypos >> scalep1;
    cin >> p2.xpos >> p2.ypos >> scalep2;

    cout << "Calling getScalePoint() for (" << p1.xpos << ", " << p1.ypos << ")" << endl;
    cout << "Calling getScalePoint() for (" << p2.xpos << ", " << p2.ypos << ")" << endl;

    p1 = getScalePoint(&p1, scalep1);
    p2 = getScalePoint(&p2, scalep2);

    cout << "Calling swapPoints()" << endl;

    swapPoints(&p1, &p2);

    cout << "p1 : " << p1.xpos <<  " " << p1.ypos << endl;
    cout << "p2 : " << p2.xpos <<  " " << p2.ypos << endl;
    
    
    return 0;
}
