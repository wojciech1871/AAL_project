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
    os <<std::setw(5) <<point.number;
    os <<std::setw(9) <<std::setprecision(3) <<std::fixed <<point.x;
    os <<std::setw(9) <<std::setprecision(3) <<std::fixed <<point.y;
    os <<std::setw(5) <<point.weight;
    return os;
}