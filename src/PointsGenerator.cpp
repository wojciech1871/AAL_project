#include "PointsGenerator.h"

PointsGenerator::PointsGenerator()
: minWeight(0), maxWeight(100), minX(-10), maxX(10), minY(-10), maxY(10)
{}

void PointsGenerator::setWeightScope(int minV, int maxV) {
    minWeight = minV;
    maxWeight = maxV;
}

void PointsGenerator::setXScope(double minV, double maxV) {
    minX = minV;
    maxX = maxV;
}

void PointsGenerator::setYScope(double minV, double maxV) {
    minY = minV;
    maxY = maxV;
}

void PointsGenerator::generateNPoints(vector_type& vectorPoints, int n) {
    destroyPoints(vectorPoints);
    vectorPoints.clear();
    vectorPoints.reserve(n);
    std::uniform_real_distribution<double> distX(minX, maxX);
    std::uniform_real_distribution<double> distY(minY, maxY);
    std::uniform_int_distribution<int> distWeight(minWeight, maxWeight);
    for(int number=0; number<n; number++) {
        double x = distX(mt);
        double y = distY(mt);
        int weight = distWeight(mt);
        vectorPoints.push_back(new Point(number, x, y, weight));
    }
}

void PointsGenerator::destroyPoints(vector_type& vectorPoints) {
    if(!vectorPoints.empty()) {
        for(auto it = vectorPoints.begin(); it != vectorPoints.end(); it++) {
            delete *it;
        }
    }
}

