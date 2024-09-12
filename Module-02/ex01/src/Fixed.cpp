#include "../include/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _fixedPointNum(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNum) {

    std::cout << "Int constructor called" << std::endl;
    _fixedPointNum = intNum << _fractionalBits;
}

Fixed::Fixed(const float floatNum) {
    
    std::cout << "Float constructor called" << std::endl;
    _fixedPointNum = (roundf(floatNum * (1 << _fractionalBits)));
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
        _fixedPointNum = copy.getRawBits();

    return (*this);
}

int Fixed::getRawBits(void) const {

    return (_fixedPointNum);
}

void Fixed::setRawBits(int const raw) {

    _fixedPointNum = raw;
}

float Fixed::toFloat(void) const {
    
    float floatNum = (float)_fixedPointNum / (1 << _fractionalBits);
    return (floatNum);
}

int Fixed::toInt(void) const {

    return (_fixedPointNum >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed) {

    COUT << fixed.toFloat();
    return (COUT);
}