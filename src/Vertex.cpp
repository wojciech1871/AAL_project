#include "Vertex.h"

Vertex::Vertex(int actIndex)
: actIndex(actIndex)
{}

int Vertex::getActIndex() const {
    return actIndex;
}

int Vertex::getRankingScore() const {
    return rankingScore;
}

void Vertex::setRankingScore(int value) {
    rankingScore = value;
}


std::ostream & operator <<(std::ostream &os, const Vertex &vertex) {
    os <<std::setw(5);
    os <<vertex.actIndex <<std::setw(5) <<vertex.rankingScore;
    return os;
}