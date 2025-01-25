#ifndef TYPES.H
#define TYPES.H

struct Point3D {
    float x, y, z;
};

struct Point2D {
    float x, y;
};

struct Edge {
    Point3D start, end;
};

#endif
