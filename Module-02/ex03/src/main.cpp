#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

int main(void) {
    
    std::cout << "**************** TEST 1 ****************" << std::endl;
    std::cout << "\n**************** INSIDE TRIANGLE ****************" << std::endl;
    Point a(-7.48, 1.75);
    Point b(-9, -1);
    Point c(-2.66, -1.33);
    Point point1(-7.06, 0.71);
    bool isInsideTriangle = bsp(a, b, c, point1);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;

    std::cout << "\n\n**************** OUTSIDE TRIANGLE ****************" << std::endl;
    Point point2(-5.18, 1.23);
    isInsideTriangle = bsp(a, b, c, point2);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;

    std::cout << "\n\n**************** ON EDGE TRIANGLE ****************" << std::endl;
    Point point3(-8.02, 0.73);
    isInsideTriangle = bsp(a, b, c, point3);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;

    std::cout << "\n\n**************** ON VERTEX TRIANGLE ****************" << std::endl;
    Point point4(-7.48, 1.75);
    isInsideTriangle = bsp(a, b, c, point4);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;


    std::cout << "\n\n**************** TEST 2 ****************" << std::endl;
    std::cout << "\n**************** INSIDE TRIANGLE ****************" << std::endl;
    Point e(4.81, 5.58);
    Point f(2.63, 3.31);
    Point g(12.32, 0.3);
    Point point5(6.14, 3.65);
    isInsideTriangle = bsp(e, f, g, point5);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;

    std::cout << "\n\n**************** OUTSIDE TRIANGLE ****************" << std::endl;
    Point point6(9.85, 2.3);
    isInsideTriangle = bsp(e, f, g, point6);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;

    std::cout << "\n\n**************** ON EDGE TRIANGLE ****************" << std::endl;
    Point point7(4.45, 2.75);
    isInsideTriangle = bsp(e, f, g, point7);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;

    std::cout << "\n\n**************** ON VERTEX TRIANGLE ****************" << std::endl;
    Point point8(12.32, 0.3);
    isInsideTriangle = bsp(e, f, g, point8);
    std::cout << "\nANSWER: " << std::endl;
    std::cout << isInsideTriangle << std::endl;
    
}
