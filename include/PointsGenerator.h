#ifndef POINTSGENERATOR_H
#define POINTSGENERATOR_H

#include <random>
#include <ctime>
#include "Point.h"

class PointsGenerator {
    int minWeight;
    int maxWeight;
    double minX;
    double maxX;
    double minY;
    double maxY;
public:
    PointsGenerator();
    void setWeightScope(int, int);
    void setXScope(double, double);
    void setYScope(double, double);

};
#endif //POINTSGENERATOR_H
