#ifndef BILLIARDS_BALL_H
#define BILLIARDS_BALL_H

#include "point.h"
#include "vector.h"
#include "board.h"
#include "line.h"
#include <iostream>

class Ball {
    int diameter{};
    Point start, center;

    static Point find_point_of_repulsion(Line from_rect, Line from_vect, Point point);
    static Point find_intersection_point(Line line1, Line line2);

public:
    Ball() = default;
    Ball(int diameter, const Point &start);

    Point hit(Point position, double impact_force, Board board);
};


#endif //BILLIARDS_BALL_H
