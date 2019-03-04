#include "Point.h"

Point::Point(int number, double x, double y, int weight)
: number(number), x(x), y(y), weight(weight)
{}

int Point::getNumber() const {
    return number;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

int Point::getWeight() const {
    return weight;
}

std::ostream & operator <<(std::ostream &os, const Point &point) {
    os <<std::setw(5);
    os <<point.number <<std::setw(5) <<point.x <<std::setw(5) <<point.y <<std::setw(5) <<point.weight;
    return os;
}