#include "../include/Fixed.hpp"

int main( void ) {

    /* Subject Tests */
    std::cout << "*** Subject Tests ***" << std::endl;
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }
    std::cout << std::endl;

    /* My Own Tests */
    std::cout << "*** My Own Tests ***" << std::endl;
    {
        Fixed a(10);
        Fixed b(8.5f);

        std::cout << "*** 1. Comparison Operator > ***" << std::endl;
        if(a > b)
            std::cout << a << " is bigger than " << b << std::endl;
        else
            std::cout << a << " is smaller than or equal " << b << std::endl;
        std::cout << "*** ***" << std::endl;

        std::cout << "*** 2. Comparison Operator == ***" << std::endl;
        if(a == b)
            std::cout << a << " is equal " << b << std::endl;
        else
            std::cout << a << " is different from " << b << std::endl;
        std::cout << "*** ***" << std::endl;

        std::cout << "*** 3. Arithmetic Operator + ***" << std::endl;
        Fixed c(a + b);
        std::cout << a << " + " << b << " = " << c << std::endl;
        std::cout << "*** ***" << std::endl;

        std::cout << "*** 4. Arithmetic Operator / ***" << std::endl;
        c = a / b;
        std::cout << a << " / " << b << " = " << c << std::endl;
        std::cout << "*** ***" << std::endl;

        std::cout << "*** 5. Pre-increment / ***" << std::endl;
        std::cout << "Before: " << a << std::endl;
        std::cout << "After: " << ++a << std::endl;
        std::cout << "*** ***" << std::endl;

        std::cout << "*** 6. Pos-increment / ***" << std::endl;
        std::cout << "Before: " << a << std::endl;
        std::cout << "After: " << a++ << std::endl;
        std::cout << "*** ***" << std::endl;

        std::cout << "*** 7. Min / ***" << std::endl;
        std::cout << "The min between " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
        std::cout << "*** ***" << std::endl;

    }

    return 0;
}
