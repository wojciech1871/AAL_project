#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <iomanip>
#include <cstddef>

class Point {
public:
    int number;
    double x;
    double y;
    int weight;
public:
    Point(int, double, double, int);

    int getNumber() const;
    double getX() const;
    double getY() const;
    int getWeight() const;

    friend std::ostream &operator<< (std::ostream &os, const Point &point);
};

#endif //POINT_H
