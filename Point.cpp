#include "Point.h"

Point::Point(double x, double y, int weight)
: x(x), y(y), weight(weight)
{}

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
    os <<point.x <<" " <<point.y <<" " <<point.weight;
    return os;
}