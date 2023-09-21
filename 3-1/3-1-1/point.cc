#include <iostream>
#include <cmath>
using namespace std;

typedef struct {
    int xpos;
    int ypos;
} Point;

void getShortest(const Point* points, int n, Point* minP) {
    double initialMinDistance = sqrt(pow((points[0].xpos - points[1].xpos), 2) + pow((points[0].ypos - points[1].ypos), 2));
    minP[0].xpos = points[0].xpos;
    minP[0].ypos = points[0].ypos;
    minP[1].xpos = points[1].xpos;
    minP[1].ypos = points[1].ypos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) { // Avoid comparing a point to itself
                double distance = sqrt(pow((points[i].xpos - points[j].xpos), 2) + pow((points[i].ypos - points[j].ypos), 2));
                if (distance < initialMinDistance) {
                    minP[0].xpos = points[i].xpos;
                    minP[0].ypos = points[i].ypos;
                    minP[1].xpos = points[j].xpos;
                    minP[1].ypos = points[j].ypos;
                    initialMinDistance = distance; 
                }
            }
        }
    }
}

void getLongest(const Point* points, int n, Point* maxP) {
    double initialMaxDistance = sqrt(pow((points[0].xpos - points[1].xpos), 2) + pow((points[0].ypos - points[1].ypos), 2));
    maxP[0].xpos = points[0].xpos;
    maxP[0].ypos = points[0].ypos;
    maxP[1].xpos = points[1].xpos;
    maxP[1].ypos = points[1].ypos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) { // Avoid comparing a point to itself
                double distance = sqrt(pow((points[i].xpos - points[j].xpos), 2) + pow((points[i].ypos - points[j].ypos), 2));
                if (distance > initialMaxDistance) {
                    maxP[0].xpos = points[i].xpos;
                    maxP[0].ypos = points[i].ypos;
                    maxP[1].xpos = points[j].xpos;
                    maxP[1].ypos = points[j].ypos;
                    initialMaxDistance = distance; 
                }
            }
        }
    }
}

int main(void) {
    Point maxP[2], minP[2];
    int n;
    cin >> n;
    Point* points = new Point[n];

    for (int i = 0; i < n; i++) {
        cin >> points[i].xpos >> points[i].ypos;
    }

    getLongest(points, n, maxP);
    getShortest(points, n, minP);

    cout << "longest: (" << maxP[0].xpos << "," << maxP[0].ypos << ") " << "(" << maxP[1].xpos << "," << maxP[1].ypos << ")" << endl;
    cout << "shortest: (" << minP[0].xpos << "," << minP[0].ypos << ") " << "(" << minP[1].xpos << "," << minP[1].ypos << ")" << endl;

    delete[] points;

    return 0;
}