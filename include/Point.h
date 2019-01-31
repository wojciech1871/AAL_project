#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cstddef>

class Point {
public:
    double x;
    double y;
    int weight;
public:
    Point(double, double, int);

    double getX() const;
    double getY() const;
    int getWeight() const;

    friend std::ostream &operator<< (std::ostream &os, const Point &point);
};

#endif //POINT_H
