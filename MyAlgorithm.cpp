#include "MyAlgorithm.h"
#include <iostream>

MyAlgorithm::MyAlgorithm()
{}

void MyAlgorithm::printPoints(std::vector<Point>& points) {
    for(auto it = points.rbegin(); it != points.rend(); it++) {
        std::cout <<*it <<std::endl;
    }
}

void MyAlgorithm::algorithmLSLamana(std::vector<Point>& points) {
    std::vector<Point> sortedPoints(points.begin(), points.end());
    sort(sortedPoints.begin(), sortedPoints.end(),
         [](const Point &p1, const Point &p2) {
             return p1.getX() < p2.getX();
         });
    printPoints(sortedPoints);
    for(auto it = sortedPoints.rbegin(); it != sortedPoints.rend(); it++) {
        double key = it->getY();
        Vertex* value = new Vertex(it->getNumber());
        auto insertIt = vertexMap.insert(std::pair<double, Vertex*>(key, value));
        auto prevMapIt = ++insertIt.first;
        if (prevMapIt != vertexMap.end()) {
            value->setNextIndex(prevMapIt->second->getActIndex());
            value->setRankingScore(prevMapIt->second->getRankingScore() + it->getWeight());
        }
        else {
            value->setNextIndex(-1);
            value->setRankingScore(it->getWeight());
        }
        int insertedRank = value->getRankingScore();
        for (auto iter = std::make_reverse_iterator(--insertIt.first); iter != vertexMap.rend(); iter++) {
            int actElRank = iter->second->getRankingScore();
            if(actElRank <= insertedRank) {
                double keyToErase = iter->first;
                iter--;
                vertexMap.erase(keyToErase);
            }
        }
    }
    for(auto it = vertexMap.rbegin(); it != vertexMap.rend(); it++) {
        std::cout << *(it->second) <<std::endl;
    }

}