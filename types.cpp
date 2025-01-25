#include "types.h"

Point3D rotateX(Point3D point, float rotation) {
    float x = point.x;
    float y = cos(rotation) * point.y - sin(rotation) * point.z;
    float z = sin(rotation) * point.y + cos(rotation) * point.z;
    return Point3D{x, y, z};
};

Point3D rotateY(Point3D point, float rotation) {
    float x = cos(rotation) * point.x - sin(rotation) * point.z;
    float y = point.y;
    float z = sin(rotation) * point.x + cos(rotation) * point.z;
    return Point3D{x, y, z};
};

Point2D project(Point3D point, float focalLength, int windowWidth, int windowHeight) {
    if (point.z == 0) {
        point.z = 0.0001f;
    }

    float x = windowWidth / 2 + (focalLength * point.x) / (focalLength * point.z) * 100;
    float y = windowHeight / 2 + (focalLength * point.y) / (focalLength * point.z) * 100;
    return Point2D{x, y};
};
