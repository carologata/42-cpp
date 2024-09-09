#ifndef POINT_H
#define POINT_H

#include "fixed.hpp"

class Point {

public:

    Point(void);
    Point(float x, float y);
    Point(const Point& copy);
    Point& operator=(const Point& copy);
    ~Point(void);

private:

    Fixed const _x;
    Fixed const _y;

};

#endif
