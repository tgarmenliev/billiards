#ifndef BILLIARDS_BOARD_H
#define BILLIARDS_BOARD_H

#include <cmath>

#include "point.h"
#include "ball.h"
#include "vector.h"
#include "line.h"
#include <iostream>

class Board {
    Point *board;

    static double distance_between_two_points(Point p1, Point p2);
    static bool check_board(Point *board);

public:
    Board() = default;
    explicit Board(Point *board);
    Board(Point l, Point r);
    bool check_if_vector_in_board(Vector vector, Point point);
    Line find_line_intersect(Vector vector, Point point);
};


#endif //BILLIARDS_BOARD_H
