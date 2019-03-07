#include "MyAlgorithm.h"
#include <iostream>

MyAlgorithm::MyAlgorithm()
: algResult(-1)
{}

void MyAlgorithm::printPoints(vector_type& points) {
    for(auto it = points.rbegin(); it != points.rend(); it++) {
        std::cout <<*it <<std::endl;
    }
}


void MyAlgorithm::printVertexPath() {
    if(!vertexPath.empty()) {
        for (auto it = vertexPath.begin(); it != vertexPath.end(); it++) {
            std::cout <<*(it) <<"\t";
        }
    }
    else {
        std::cout <<"Vector is empty" <<std::endl;
    }
}

int MyAlgorithm::returnAlgorithmResult() {
    return algResult;
}

void MyAlgorithm::runAlgorithmLSLamana(std::vector<Point>& points) {
    vector_type sortedPoints(points.begin(), points.end());
    map_type vertexMap;

    sortPointsByX(sortedPoints);
    for(auto it = sortedPoints.rbegin(); it != sortedPoints.rend(); it++) {
        double key = it->getY();
        auto value = new Vertex(it->getNumber());
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
    createVertexPathFromMap(vertexMap);
    algResult = vertexMap.begin()->second->getRankingScore();
    destroyMap(vertexMap);
}

void MyAlgorithm::sortPointsByX(vector_type& points) {
    sort(points.begin(), points.end(),
         [](const Point &p1, const Point &p2) {
             return p1.getX() < p2.getX();
         });
}

void MyAlgorithm::createVertexPathFromMap(map_type& vertexMap) {
    if(!vertexPath.empty()) {
        vertexPath.clear();
    }
    if(!vertexMap.empty()) {
        int nextNumber;
        nextNumber = vertexMap.begin()->second->getNextIndex();
        vertexPath.reserve(vertexMap.size());
        vertexPath.push_back(vertexMap.begin()->second->getActIndex());
        for(auto it = ++vertexMap.begin(); it != vertexMap.end(); it++){
            int actIndex = it->second->getActIndex();
            if(nextNumber==actIndex) {
                vertexPath.push_back(actIndex);
                nextNumber = it->second->getNextIndex();
            }
        }
    }

}

void MyAlgorithm::destroyMap(map_type& map) {
    if(!map.empty()) {
        for(auto it=map.begin(); it!=map.end(); it++) {
            delete it->second;
        }
    }
}