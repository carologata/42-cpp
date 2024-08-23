#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(void) : fixedPointNum(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNum) {

    std::cout << "Int constructor called" << std::endl;
    fixedPointNum = intNum << fractionalBits;
}

Fixed::Fixed(const float floatNum) {
    
    std::cout << "Float constructor called" << std::endl;
    fixedPointNum = (roundf(floatNum * (1 << fractionalBits)));
    // fixedPointNum = (roundf(floatNum << fractionalBits)); << is just possible for integer values

}

Fixed::~Fixed(void) {

    std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& copy) {
    
    std::cout << "Copy constructor called" << std::endl;

    *this = copy;
}

/* Assignment operator */
Fixed& Fixed::operator=(const Fixed& copy) {
    
    std::cout << "Copy assignment operator called" << std::endl;

    if(this != &copy)
        fixedPointNum = copy.getRawBits();

    return (*this);
}

int Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointNum);
}

void Fixed::setRawBits(int const raw) {

    fixedPointNum = raw;
}

float Fixed::toFloat(void) const {
    
    return ((float)(fixedPointNum / (1 << fractionalBits)));
}

int Fixed::toInt(void) const {

    return (fixedPointNum >> fractionalBits);
}

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed) {

    COUT << fixed.toFloat();
    return (COUT);
}