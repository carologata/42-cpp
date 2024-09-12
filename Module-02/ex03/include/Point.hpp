#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

public:

    Point(void);
    Point(float x, float y);
    Point(const Point& copy);
    Point& operator=(const Point& copy);
    ~Point(void);

    int     getFixedX(void) const;
    int     getFixedY(void) const;
    
    float   getFloatX(void) const;
    float   getFloatY(void) const;


private:

    Fixed _x;
    Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
