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
    Point p1 = Point(1, 10, 10, 15);
    Point p2 = Point(2, 8, 2, 10);
    Point p3 = Point(3, 7, 4, 11);
    Point p4 = Point(4, 4, 1, 4);
    Point p5 = Point(5, 5, 11, 30);
    cout <<p1 <<endl;
    cout <<p2 <<endl;
    cout <<p3 <<endl;
    cout <<p4 <<endl;
    cout <<p5 <<endl;

    vector<Point> points;
    MyAlgorithm myAg = MyAlgorithm();

    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);

    myAg.runAlgorithmLSLamana(points);
//
//        cout <<"After sorted" <<endl;
//        for(auto it = points.rbegin(); it != points.rend(); it++) {
//            cout <<*it <<endl;
//        }
//
//        pointsMap[p1.getY()] = new Vertex(&p1);
//        pointsMap[p2.getY()] = new Vertex(&p2);
//        pointsMap[p3.getY()] = new Vertex(&p3);
//        pointsMap[p4.getY()] = new Vertex(&p4);
//
//        cout <<"Map by y" <<endl;
//        for(auto it = pointsMap.begin(); it != pointsMap.end(); it++) {
//
//        }
//
//        myAg.printPoints();
    int result = myAg.returnAlgorithmResult();
    cout <<"alg result is " <<result <<endl;
    myAg.printVertexPath();
}
