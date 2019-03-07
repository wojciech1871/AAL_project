#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Point.h"
#include "Vertex.h"
#include "MyAlgorithm.h"

void txtFileParser(std::vector<Point>& points) {
    int number, weight;
    double x, y;
    while (std::cin >>number >>x >>y >>weight) {
        points.emplace_back(Point(number, x, y, weight));
    }
}
int main() {
    std::vector<Point> pointsVector;
    MyAlgorithm myAlgorithm;
    txtFileParser(pointsVector);
    myAlgorithm.runAlgorithmLSLamana(pointsVector);
    std::cout <<"Result: " <<myAlgorithm.returnAlgorithmResult() <<std::endl;
}
