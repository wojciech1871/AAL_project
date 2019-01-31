#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "Vertex.h"

class MyAlgorithm{
public:
    std::vector<Point>& points;
    MyAlgorithm(std::vector<Point>&);
    void printPoints();
};

#endif //MYALGORITHM_H
