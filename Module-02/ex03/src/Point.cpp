#include "../include/Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {}

Point& Point::operator=(const Point& copy) {

    (void)copy;
    return (*this);
}

Point::~Point(void) {}

int Point::getFixedX(void) {

    return (_x.getRawBits());
}

int Point::getFixedY(void) {

    return (_y.getRawBits());
}

float Point::getFloatX(void) {
    
    return (_x.toFloat());
}

float Point::getFloatX(void) {
    
    return (_x.toFloat());
}