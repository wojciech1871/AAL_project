#include "MyAlgorithm.h"

MyAlgorithm::MyAlgorithm()
: algResult(-1), firstVertex(-1)
{}

void MyAlgorithm::printPoints(const vector_type& points) const {
    std::cout <<std::setw(5) <<"Number";
    std::cout <<std::setw(9) <<"X   ";
    std::cout <<std::setw(9) <<"Y   ";
    std::cout <<std::setw(5) <<"Weight" <<std::endl;
    for(auto it = points.begin(); it != points.end(); it++) {
        std::cout <<*it <<std::endl;
    }
}

void MyAlgorithm::printVertexPath() {
    if(!vertexPath.empty()) {
        int actIndex = firstVertex;
        int nextIndex = vertexPath[actIndex];
        int pathSize = 0;
        while (actIndex != -1){
            pathSize++;
            std::cout <<actIndex <<"\t";
            actIndex = nextIndex;
            nextIndex = vertexPath[actIndex];
        }
    }
    else {
        std::cout <<"Vector is empty" <<std::endl;
    }
}

int MyAlgorithm::returnAlgorithmResult() const {
    return algResult;
}

void MyAlgorithm::runAlgorithmLSLamana(const vector_type & points) {
    int nextIndex;
    int rankingScore;
    double key;
    Vertex* value;
    vector_type sortedPoints(points.begin(), points.end());
    map_type vertexMap;
    sortPointsByX(sortedPoints);
    vertexPath.clear();
    algResult = -1;
    firstVertex = -1;
    for(auto it = sortedPoints.rbegin(); it != sortedPoints.rend(); it++) {
        key = it->getY();
        value = new Vertex(it->getNumber());
        auto insertIt = vertexMap.insert(std::pair<double, Vertex*>(key, value));
        auto prevMapIt = ++insertIt.first;
        if (prevMapIt != vertexMap.end()) {
            nextIndex = prevMapIt->second->getActIndex();
            rankingScore = prevMapIt->second->getRankingScore() + it->getWeight();
        }
        else {
            nextIndex = -1;
            rankingScore = it->getWeight();
        }
        value->setRankingScore(rankingScore);
        vertexPath[it->getNumber()] = nextIndex;

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
    algResult = vertexMap.begin()->second->getRankingScore();
    firstVertex = vertexMap.begin()->second->getActIndex();
    destroyMap(vertexMap);
}

void MyAlgorithm::sortPointsByX(vector_type& points) {
    sort(points.begin(), points.end(),
         [](const Point &p1, const Point &p2) {
             return p1.getX() < p2.getX();
         });
}

void MyAlgorithm::destroyMap(map_type& map) {
    if(!map.empty()) {
        for(auto it=map.begin(); it!=map.end(); it++) {
            delete it->second;
        }
    }
}