#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

int main(void) {
    
    Point const a(-11.02, 3.27);
    Point const b(-12, -0.61);
    Point const c(-7.18, 1.43);
    Point const point(-10.1, 1.37);

    bool isInsideTriangle = bsp(a, b, c, point);

    std::cout << isInsideTriangle << std::endl;
}