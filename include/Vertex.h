#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <iomanip>

class Vertex {
    int actIndex;
    int rankingScore;
public:
    Vertex(int);

    int getActIndex() const;
    int getRankingScore() const;
    void setRankingScore(int);

    friend std::ostream &operator<< (std::ostream &os, const Vertex &vertex);
};

#endif //VERTEX_H
