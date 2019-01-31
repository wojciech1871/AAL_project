#include "MyAlgorithm.h"
#include <iostream>

MyAlgorithm::MyAlgorithm(std::vector<Point>& points)
: points(points)
{}

void MyAlgorithm::printPoints() {
    for(auto it = points.rbegin(); it != points.rend(); it++) {
        std::cout <<*it <<std::endl;
    }
}