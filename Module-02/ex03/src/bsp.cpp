#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

bool isOnSameSide(Point& const pointA, Point& const pointB, Point& const pointC, Point& const pointP) {

    float pointABx = pointB.getFloatX() - pointA.getFloatX();  
    float pointABy = pointB.getFloatY() - pointA.getFloatY();  

    float pointACx = pointC.getFloatX() - pointA.getFloatX(); 
    float pointACy = pointC.getFloatY() - pointA.getFloatY();

    float pointAPx = pointP.getFloatX() - pointA.getFloatX(); 
    float pointAPy = pointP.getFloatY() - pointA.getFloatY();

    float crossProductABandAC = (pointABx * pointACy) - (pointABy * pointACx);
    float crossProductABandAP = (pointABx * pointAPy) - (pointABy * pointAPx);
    
    return (crossProductABandAC * crossProductABandAP >= 0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {

    bool isOnSameSideAB = isOnSameSide(a, b, c, point);
    bool isOnSameSideBC = isOnSameSide(b, c, a, point);
    bool isOnSameSideCA = isOnSameSide(c, a, b, point);

    return (isOnSameSideAB && isOnSameSideBC && isOnSameSideCA);
}   