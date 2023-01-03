#include "line.h"

// TODO - constructs a line given a point and a vector
// Конструира се права по начина, показан в час за вектор и точка.
Line::Line(const Point p, const Vector& v)
{
    this->A = v.y;
    this->B = -v.x;
    this->C = (v.x * p.y) - (v.y * p.x);
}

// TODO - constructs a line given two points
/*
	Обяснителни бележки към функцията:
	Когато имаме само две точки може да бъде конструиран вектор. Тоест за да може да бъде
	преизползван първият конструктор за права в този конструктор, трябва да бъде
	конструиран вектор. Заедно с двете подадени точки се конструира вектор от класа
	за вектор. След това се получават вектор и две точки. Поради тази причина се извиква
	контрукторът на права с точка и вектор и също да бъде избегнато повторението на код.
	Избира се първата точка и се подава полученият вектор на конструктора за права.
	Избира се първата точка, поради начина за конструиране на вектор, показан в час.
	Така може да бъде конструирано параметричното уравнение на правата.
*/
Line::Line(const Point p1, const Point p2) : Line(p1, Vector(p1,p2)) {}

// TODO - checks if two lines a parallel to eachother
/*
	Обяснителни бележки:
	Две прави могат да бъдат паралелни, когато произведението на
	кофициентите им на кръст е равно. Тоест когато коефициентите им спрямо
	осите са на еднакво разстояние един от друг, то двете прави ще
	бъдат паралелни. В случая се умножава А на едната права с В на
	другата и ако това е равно на В на едната права умножено с А на другата
	права, то двете прави ще бъдат паралелни.
*/
bool Line::are_parallel(const Line& other) const
{
    if (this->A * other.B == other.A * this->B)
        return true;
    return false;
}

// TODO - checks if two lines are orthogonal (perpendicular)
/*
	Обяснителни бележки:
	В клас сме казали, че скаларното произведение на колинеарните вектори на
	две перпендикулярни прави е нула.
	Тоест ако тук се умножат скаларно коефициентите A и B на двете прави и техният сбор се
	получи да бъде нула, тогава двете прави ще бъдат колинеарни.
*/
bool Line::is_orthogonal(const Line& other) const
{
    if ((this->A * other.A) + (this->B * other.B) == 0)
        return true;
    return false;
}

// TODO - returns the vector that is colinear to the line
// В клас сме казали, че когато направим един вектор от права, то той ще е
// колинеарен на тази права.
Vector Line::colinear() const
{
    return Vector(-this->B, this->A);
}

// TODO - returns the vector that is orthogonal to the line
// Ортогонален вектор на една може да бъде получен като за
// х и у на вектора бъдат подадени съответно А и В от
// параметричното уравнение на правата.
Vector Line::orthogonal() const
{
    return Vector(this->A, this->B);
}

// TODO - returns a line, passing through the point p, that is parallel to the line
// Намира се колинеарен вектор на правата. След това се прави нова права
// с точката и колинеарния вектор, с помощта на конструктора в класа Line.
// Накрая се връща новата права.
Line Line::parallel(const Point p) const
{
    Vector parallel_vector = this->colinear();
    Line result = Line(p, parallel_vector);
    return result;
}

// TODO - returns a line, passing through the point p, that is orthogonal to the line
// Намира се ортогонален вектор на правата. След това се прави нова права
// с точката и намерения колинеарен вектор, с помощта на конструктора за
// точка и вектор в класа Line. Накрая се връща новата права.
Line Line::orthogonal(const Point p) const
{
    Vector orthogonal_vector = this->orthogonal();
    Line result = Line(p, orthogonal_vector);
    return result;
}

Point Line::find_symethrical(Point point) const
{
    double x = (B * B * A * point.x) - (2 * A * A * B * point.y) - (2 * A * A * C) - (A * A * A * point.x);
    double quotinent = (A * A) + (B * B);
    double y = (A * A * point.y) - (B * B * point.y) - (2 * B * C) - (2 * A * B * point.x);

    return Point(x / (A * quotinent), y / quotinent);
}
