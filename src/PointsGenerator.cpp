#include "PointsGenerator.h"

PointsGenerator::PointsGenerator()
: minWeight(0), maxWeight(100), minX(-10), maxX(10), minY(-10), maxY(10)
{
    srand(time(NULL));
}

void PointsGenerator::setWeightScope(int minV, int maxV) {
    minWeight = minV;
    maxWeight = maxV;
    return;
}

void PointsGenerator::setXScope(double minV, double maxV) {
    minX = minV;
    maxX = maxV;
    return;
}

void PointsGenerator::setYScope(double minV, double maxV) {
    minY = minV;
    maxY = maxV;
    return;
}

