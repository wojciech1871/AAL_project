#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <iostream>
#include <algorithm>
#include "Types.h"

class MyAlgorithm {
    path_type vertexPath;
    int algResult;
    int firstVertex;
public:
    MyAlgorithm();
    void printPoints(const vector_type&) const;
    void printVertexPath();
    int returnAlgorithmResult() const;
    void runAlgorithmLSLamana(const vector_type&);
    void sortPointsByX(vector_type&);
    void destroyMap(map_type&);
};
#endif //MYALGORITHM_H
