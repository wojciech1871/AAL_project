#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#include "Point.h"
#include "Vertex.h"
#include "MyAlgorithm.h"

using namespace std;

int main() {
    cout <<"Points" <<endl;
    Point p1 = Point(3, 4, 1);
    Point p2 = Point(2, -3, 5);
    Point p3 = Point(10, 7, 5);
    Point p4 = Point(-2, 3, 10);
    cout <<p1 <<endl;
    cout <<p2 <<endl;
    cout <<p3 <<endl;
    cout <<p4 <<endl;

    vector<Point> points;
    vector<Point> points2;
    map<double, Vertex*> pointsMap;
    MyAlgorithm myAg = MyAlgorithm(points);

    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

    for(auto it = points.begin(); it != points.end(); it++) {
        cout <<*it <<endl;
    }

    sort(points.begin(), points.end(),
            [](const Point &p1, const Point &p2) {
        return p1.getX() < p2.getX();
    });

    cout <<"After sorted" <<endl;
    for(auto it = points.rbegin(); it != points.rend(); it++) {
        cout <<*it <<endl;
    }

    pointsMap[p1.getY()] = new Vertex(&p1);
    pointsMap[p2.getY()] = new Vertex(&p2);
    pointsMap[p3.getY()] = new Vertex(&p3);
    pointsMap[p4.getY()] = new Vertex(&p4);

    cout <<"Map by y" <<endl;
    for(auto it = pointsMap.begin(); it != pointsMap.end(); it++) {

    }

    myAg.printPoints();
}
