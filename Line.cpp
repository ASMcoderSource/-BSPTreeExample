#include "Line.h"


Line::Line(Point A, Point B) {
    initByPoints(A, B);
}

void Line::initByPoints(Point A, Point B) {
    if ((B.x) < (A.x))
        std::swap(A, B);
    double k, c;
    if (B.x - A.x == 0)
        k = (B.y - A.y) / ((B.x + 1e-6) - A.x);
    else
        k = (B.y - A.y) / (B.x - A.x);
    c = A.y + (-A.x * k);
    linear_params.k = k; {}
    linear_params.c = c;

    double a, b; // c;
    b = (B.x - A.x) / (B.y - A.y);
    if (b != 0) {
        a = -k * b;
        c = c * b;
    }
    else {
        a = 1;
        b = 0;
        c = A.x;
    }
    base_params.a = a;
    base_params.b = b;
    base_params.c = c;
    Line::A = A;
    Line::B = B;
}

Point Line::intersectionPoint(Line& b) {
    double x1 = base_params.a / -base_params.b;
    double c1 = -base_params.c / -base_params.b;
    double x2 = b.base_params.a / -b.base_params.b;
    double c2 = -b.base_params.c / -b.base_params.b;
    Point intersection;
    intersection.x = (c2 - c1) / (x1 - x2);
    intersection.y = intersection.x * x1 + c1;
    return intersection;
}

double Line::lenghtToLine(Point& point) {
    return point.x * base_params.a + point.y * base_params.b - base_params.c;
}

bool Line::isPointInsideSegment(Point& point) {
    if (point.x < A.x || point.x > B.x)
        return false;
    if (A.y > B.y) {
        if (point.y > A.y)
            return false;
        if (point.y < B.y)
            return false;
    } else {
        if (point.y > B.y)
            return false;
        if (point.y < A.y)
            return false;
    }
    return true;
}
