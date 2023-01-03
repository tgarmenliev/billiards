#include "board.h"

Board::Board(Point *board)
{
    if(check_board(board))
        this->board = board;
}

Board::Board(Point l, Point r)
{
    Point *new_board = new Point[4];
    new_board[0] = l;
    new_board[1] = Point(r.x, l.y);
    new_board[2] = Point(l.x, r.y);
    new_board[3] = r;

    if(check_board(new_board))
        this->board = new_board;
}

double Board::distance_between_two_points(Point p1, Point p2)
{
    return sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));
}

bool Board::check_board(Point *board)
{
    double a = distance_between_two_points(board[0], board[1]);
    double b = distance_between_two_points(board[0], board[2]);

    if(a == (2 * b) || b == (2 * a))
        return true;

    return false;
}

bool Board::check_if_vector_in_board(Vector vector, Point point)
{
    Line line_ball = Line(point, vector);
    for(int i = 0; i < 4; i++)
    {
        Line curr_line_in_board;
        if(i == 3)
            curr_line_in_board = Line(board[i], board[0]);
        else
            curr_line_in_board = Line(board[i], board[i+1]);
        if(!curr_line_in_board.are_parallel(line_ball))
            return true;
    }
    return false;
}

Line Board::find_line_intersect(Vector vector, Point point) {
    Line line_ball = Line(point, vector);
    for(int i = 0; i < 4; i++)
    {
        Line curr_line_in_board;
        if(i == 3)
            curr_line_in_board = Line(board[i], board[0]);
        else
            curr_line_in_board = Line(board[i], board[i+1]);
        if(!curr_line_in_board.are_parallel(line_ball))
            return curr_line_in_board;
    }
    return line_ball;
}
