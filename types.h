#ifndef TYPES.H
#define TYPES.H

#include <cmath>

struct Point3D {
    float x, y, z;
};

struct Point2D {
    float x, y;
};

struct Edge {
    int start, end;
};

Point3D rotateX(Point3D point);
Point3D rotateY(Point3D point);
Point2D project(Point3D point);

#endif
