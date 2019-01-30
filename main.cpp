# include <iostream>
# include <vector>
# include "Point.h"

using namespace std;

int main() {
    Point p1 = Point(3, 4, 1);
    Point p2 = Point(2, 3, 5);
    Point p3 = Point(10, 3, 5);
    Point p4 = Point(-2, 3, 10);
    cout <<p1 <<endl;
    cout <<p2 <<endl;
    cout <<p3 <<endl;
    cout <<p4 <<endl;

    vector<Point> points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

    for(auto it = points.begin(); it != points.end(); it++) {
        cout <<*it <<endl;
    }

    for(auto it = points.begin(); it != points.end(); it++) {
        cout <<*it <<endl;
    }
}
