//
// Created by User on 2021/5/3.
//

#ifndef OOP_HW4_CONVEXHULL_H
#define OOP_HW4_CONVEXHULL_H
#include "Point.h"
#include "Line.h"
#include <vector>

#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <limits>
#define PI 3.1415926535897931
#define SWAP(X,Y,T) ((T)=(X),(X)=(Y),(Y)=(T))
using namespace std;
class ConvexHull {
public:
    void FindConvexHull_brutal(const vector<Point> &input, vector<Point> &output);
    void FindConvexHull_Jarvis(const vector<Point> &input, vector<Point> &output);
private:
    Line FindLine(const Point &p, const Point &q);
    bool isOnRight(const Point &p, const Point &q, const Point &r);
    Point FindLowestPoint(vector<Point>&input);
    double ComputeAngle(const Point &p, const Point &q, const Point &r);
    double orientation(const Point &p, const Point &q, const Point &r);
    void brutalSort(vector<Point>&input,vector<Point>&output);
    double computeAngle(Point &o, Point &src);
};
inline double length(const Point &p, const Point &q);

#endif //OOP_HW4_CONVEXHULL_H
