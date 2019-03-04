#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <iomanip>

class Vertex {
    int actIndex;
    int nextIndex;
    int rankingScore;
public:
    Vertex(int);

    int getActIndex() const;
    int getNextIndex() const;
    int getRankingScore() const;
    void setRankingScore(int);
    void setNextIndex(int);

    friend std::ostream &operator<< (std::ostream &os, const Vertex &vertex);
};

#endif //VERTEX_H
