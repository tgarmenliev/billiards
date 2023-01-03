#ifndef BILLIARDS_VECTOR_H
#define BILLIARDS_VECTOR_H

#include "point.h"
#include <cmath>

class Vector {
public:
    double x, y;

    Vector() : x(0), y(0) {}
    Vector(int x, int y) : x(x), y(y) {}
    Vector(const Point p1, const Point p2);

    Vector sum(const Vector& other) const;
    Vector times_num(double num) const;

    bool is_colinear(const Vector& other) const;
    double length() const;
    int dot_product(const Vector& other) const;

    int getX() const;

    int getY() const;
};


#endif //BILLIARDS_VECTOR_H
