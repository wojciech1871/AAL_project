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
    void printPoints(const vector_type&) const;
    void printVertexPath()const;
    int returnAlgorithmResult() const;
    void runAlgorithmLSLamana(const vector_type&);
    void createVertexPathFromMap(const map_type&);
    void sortPointsByX(vector_type&);
    void destroyMap(map_type&);
};
#endif //MYALGORITHM_H
