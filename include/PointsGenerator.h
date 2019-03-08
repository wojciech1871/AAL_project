#ifndef POINTSGENERATOR_H
#define POINTSGENERATOR_H

#include <iostream>
#include <random>
#include <ctime>
#include "Types.h"

class PointsGenerator {
    int minWeight;
    int maxWeight;
    double minX;
    double maxX;
    double minY;
    double maxY;
    std::random_device rd;
    std::mt19937 mt{rd()};
public:
    PointsGenerator();
    void setWeightScope(int, int);
    void setXScope(double, double);
    void setYScope(double, double);
    void generateNPoints(vector_type&, int);
};
#endif //POINTSGENERATOR_H
