#include "ball.h"

Ball::Ball(int diameter, const Point &start) : diameter(diameter), start(start), center(start) {}

Point Ball::hit(Point position, double impact_force, Board board) {
    if(impact_force == (double)1)
        return position;

    auto *vector = new Vector(start, position);

    Vector new_position_vector = vector->times_num(impact_force - 1);

    Point new_pos_point = Point(position.x + new_position_vector.getX(), position.y + new_position_vector.getY());

    if(board.check_if_vector_in_board(new_position_vector, new_pos_point))
    {
        return new_pos_point;
    }

    // znachi imame otbluskvane
    // izchisli tochkata

    Line line_intersect = board.find_line_intersect(new_position_vector, new_pos_point);

    Line new_pos_line = Line(new_pos_point, new_position_vector);

    Point final_point = find_point_of_repulsion(line_intersect, new_pos_line, new_pos_point);

    return final_point;
}

Point Ball::find_point_of_repulsion(Line from_rect, Line from_vect, Point point)
{
    Point intersect_rect_vect = find_intersection_point(from_rect, from_vect);

    //Point find_symethrical_point_other_side = from_rect.find_symethrical(point);

    //Line other_sym_line = Line(intersect_rect_vect, find_symethrical_point_other_side);

    Line orth_line_to_rect = from_rect.orthogonal(intersect_rect_vect);

    Point final_point_replusion = orth_line_to_rect.find_symethrical(point);

    return final_point_replusion;
}

Point Ball::find_intersection_point(Line line1, Line line2)
{
    double x = (line2.B * line1.C) - (line1.B * line2.C);
    double quotinent =  (line2.A * line1.B) - (line1.A - line2.B);
    double y = (line1.A * line2.C) - (line2.A * line1.C);

    return Point(x/quotinent, y/quotinent);
}
