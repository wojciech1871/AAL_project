#ifndef VERTEX_H
#define VERTEX_H

#include "Point.h"

class Vertex {
    Point* actPoint;
    Point* nextPoint;
    int vmax;
public:
    Vertex(Point*, Point* = nullptr);
};

#endif //VERTEX_H
