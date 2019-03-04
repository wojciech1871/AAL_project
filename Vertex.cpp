#include "Vertex.h"

Vertex::Vertex(int actIndex)
: actIndex(actIndex)
{}

int Vertex::getActIndex() const {
    return actIndex;
}

int Vertex::getNextIndex() const {
    return nextIndex;
}

int Vertex::getRankingScore() const {
    return rankingScore;
}

void Vertex::setRankingScore(int value) {
    rankingScore = value;
}

void Vertex::setNextIndex(int value) {
    nextIndex = value;
}

std::ostream & operator <<(std::ostream &os, const Vertex &vertex) {
    os <<std::setw(5);
    os <<vertex.actIndex <<std::setw(5) <<vertex.nextIndex <<std::setw(5) <<vertex.rankingScore;
    return os;
}