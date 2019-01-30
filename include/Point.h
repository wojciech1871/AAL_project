#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <map>

class Point {
    double x;
    double y;
    int weight;
public:
    Point(double, double, int);

    friend std::ostream &operator<< (std::ostream &os, const Point &point);
};
#endif //POINT_H
