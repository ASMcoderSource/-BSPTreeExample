#ifndef LINE_H
#define LINE_H
#include <cmath>
#include <algorithm>

struct Point {
    double x, y;
};

struct BaseLineParameters {
    // Ax + By - C = 0
    double a, b, c;
};

struct LinearParameters {
    // y = kx + c
    double k, c;
};

struct Line {
    Point A, B;
    BaseLineParameters base_params;
    LinearParameters linear_params;

public:
    Line(Point A, Point B);
    void initByPoints(Point A, Point B);
    Point intersectionPoint(Line& b);
    double lenghtToLine(Point& point);
    bool isPointInsideSegment(Point& point);
};

#endif // LINE_H
