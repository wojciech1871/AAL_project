#include "Vertex.h"

Vertex::Vertex(Point* actPoint, Point* nextPoint)
: actPoint(actPoint), nextPoint(nextPoint), vmax(0)
{}

Point& Vertex::getActPoint() {
    return *actPoint;
}

Point& Vertex::getNextPoint() {
    return *nextPoint;
}