#ifndef BILLIARDS_POINT_H
#define BILLIARDS_POINT_H


struct Point {
    double x, y;

    // Default constructor
    Point() : x(0), y(0) {}

    // Constructor
    Point(double x, double y) : x(x), y(y) {}
};


#endif //BILLIARDS_POINT_H
