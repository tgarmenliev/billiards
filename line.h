#ifndef BILLIARDS_LINE_H
#define BILLIARDS_LINE_H

#include "vector.h"

class Line {
public:
    double A, B, C;

    Line(int A = 0, int B = 0, int C = 0) : A(A), B(B), C(C) {}
    Line(const Point p, const Vector& v);
    Line(const Point p1, const Point p2);

    bool are_parallel(const Line& other) const;
    bool is_orthogonal(const Line& other) const;

    Vector colinear() const;
    Vector orthogonal() const;

    Line parallel(const Point p) const;
    Line orthogonal(const Point p) const;

    Point find_symethrical(Point point) const;
};


#endif //BILLIARDS_LINE_H
