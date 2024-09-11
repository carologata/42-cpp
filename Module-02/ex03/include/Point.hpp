#ifndef POINT_H
#define POINT_H

#include "./Fixed.hpp"

class Point {

public:

    Point(void);
    Point(float x, float y);
    Point(const Point& copy);
    Point& operator=(const Point& copy);
    ~Point(void);

    int     getFixedX(void);
    int     getFixedY(void);
    
    float   getFloatX(void);
    float   getFloatY(void);


private:

    Fixed _x;
    Fixed _y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point)

#endif
