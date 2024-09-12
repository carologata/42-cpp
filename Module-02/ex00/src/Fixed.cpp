#include "../include/Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _fixedPointNum(0) {

    std::cout << "Default constructor called" << std::endl;
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

    std::cout << "getRawBits member function called" << std::endl;
    return (_fixedPointNum);
}

void Fixed::setRawBits(int const raw) {

    _fixedPointNum = raw;
}