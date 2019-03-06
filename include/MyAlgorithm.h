#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Point.h"
#include "Vertex.h"

class MyAlgorithm {
    using vector_type = std::vector<Point>;
    using map_type = std::map<double, Vertex*>;
    using path_type = std::vector<int>;

    path_type vertexPath;
    int algResult;

public:
    MyAlgorithm();
    void printPoints(vector_type&);
    void printVertexPath();
    int returnAlgorithmResult();
    void runAlgorithmLSLamana(vector_type&);
    void createVertexPathFromMap(map_type&);
    void sortPointsByX(vector_type&);
    void destroyMap(map_type&);
};
#endif //MYALGORITHM_H
