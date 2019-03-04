#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Point.h"
#include "Vertex.h"

class MyAlgorithm{
    std::map<double, Vertex*> vertexMap;
public:
    MyAlgorithm();
    void printPoints(std::vector<Point>&);

    void algorithmLSLamana(std::vector<Point>&);
};

#endif //MYALGORITHM_H
