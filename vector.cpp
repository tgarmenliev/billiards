#include "vector.h"

// TODO - constructs vector from 2 points
// Конструира се вектор с две точки като от координатите на
// втората се изваждат тези на първата и се получават координатите на вектора.
Vector::Vector(const Point p1, const Point p2)
{
    this->x = p2.x - p1.x;
    this->y = p2.y - p1.y;
}

// TODO - returns the sum of two vectors (which is also e vector)
// При събирането на вектори се събират техните координати и след
// това се конструира новият вектор.
Vector Vector::sum(const Vector& other) const
{
    Vector result = Vector(this->x + other.x, this->y + other.y);
    return result;
}

// TODO - returns the product of a vector and a number (which is also e vector)
// Умножението на вектор е създаване на нов вектор с умножени координатите на
// първия по даденото число.
Vector Vector::times_num(double num) const
{
    Vector result = Vector(this->x * num, this->y * num);
    return result;
}

// TODO - returns a boolean value, answering the question whether the current
// vector and another ("other") are collinear
/*
	Обяснителни бележки към функцията:
	Два вектора могат да бъдат колинеарни при няколко варианта.
	Едниният от тях е ако единият от векторите се съдържа в другия.
	Тоест ако имаме два вектора 'а' и 'b', тогава ако а = n.b и 'n' е някакво число,
	тогава двата вектора ще бъдат колинеарни.
	Друг вариант, по който може да се докаже, че два вектора са колинеарни е като ги умножим
	на кръст и се получат еднакви резултати, тогава двата вектора ще бъдат колинеарни.
	Тоест ако координатите на тези два вектора са на равно разстояние, то двата
	вектора са колинеарни. Прави се отношение на координатите на векторите, умножаваме
	на кръст, за да бъде избегнато делението на нула с координатите
	на векторите и така се разбира дали тези два вектора са колинеарни или не.
	В моята функция съм използвал този втори вариант, за да докажа, че векторите са
	колинеарни или не са. Умножавам х на единия вектор с у на другия от едната страна,
	а от другата - у на единия с х на другия вектор.
	Умножавам на кръст и ако от двете страни се получат еднакви
	резултати, или ако издвадим от едната страна - другата се получава 0, тогава
	векторите са колинеарни.
*/
bool Vector::is_colinear(const Vector& other) const
{
    if (this->x * other.y == other.x * this->y)
        return true;
    return false;
}

// TODO - returns the length of the current vector
// Намирам дължината на вектора по формулата на Питагор,
// с получения триъгълник от х и у на вектора.
double Vector::length() const
{
    return sqrt((this->x * this->x) + (this->y * this->y));
}

// TODO - returns the dot(scalar) product of the current vector and another
// Скаларното произведение се намира като умножа всеки от параметрите на вектора
// с този на другия вектор и събера.
int Vector::dot_product(const Vector& other) const
{
    return (this->x * other.x) + (this->y * other.y);
}

int Vector::getX() const {
    return x;
}

int Vector::getY() const {
    return y;
}
