#include <iostream>
#include "ball.h"
#include "board.h"
#include "point.h"
#include <string>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Ball *ball = new Ball(0, Point(280, 70));

    auto board = new Board(Point(2,2), Point(10,6));

    Point new_pos = ball->hit(Point(230, 110), 2, *board);
    cout << "x: " << new_pos.x << " y: " << new_pos.y << endl;

    return 0;
}
