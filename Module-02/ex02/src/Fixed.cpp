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
}

Fixed::~Fixed(void) {

    std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& copy) {
    
    std::cout << "Copy constructor called" << std::endl;

    *this = copy;
}

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

bool Fixed::operator>(const Fixed &compareObj) {
    
    return (this->_fixedPointNum > compareObj.getRawBits());
}

bool Fixed::operator<(const Fixed& compareObj) {

    return (this->_fixedPointNum < compareObj.getRawBits());
}

bool Fixed::operator>=(const Fixed& compareObj) {

    return (this->_fixedPointNum >= compareObj.getRawBits());
}

bool Fixed::operator<=(const Fixed& compareObj) {

    return (this->_fixedPointNum <= compareObj.getRawBits());
}

bool Fixed::operator==(const Fixed& compareObj) {

    return (this->_fixedPointNum == compareObj.getRawBits());
}

bool Fixed::operator!=(const Fixed& compareObj) {

    return (this->_fixedPointNum != compareObj.getRawBits());
}

Fixed Fixed::operator+(const Fixed& arithmeticObj) {

    return (this->toFloat() + arithmeticObj.toFloat());
}

Fixed Fixed::operator-(const Fixed& arithmeticObj) {

    return (this->toFloat() - arithmeticObj.toFloat());
}

Fixed Fixed::operator*(const Fixed& arithmeticObj) {

    return (this->toFloat() * arithmeticObj.toFloat());
}

Fixed Fixed::operator/(const Fixed& arithmeticObj) {

    return (this->toFloat() / arithmeticObj.toFloat());
}


/* Pre-increment */
Fixed& Fixed::operator++(void) {
    
    this->_fixedPointNum++;
    return (*this);
}

/* Pos-increment
is enough to tell the compiler that this is the post-increment version of operator++, 
even though the int parameter isn’t used. 
For the post-increment (x++) operator, you should return a copy of the object by value (Fixed), 
not a reference, because the post-increment operation needs to return the original value before 
the increment, and that value will no longer exist after the operation if returned by reference.
*/
Fixed Fixed::operator++(int) {
    
    Fixed tmp = *this;
    this->_fixedPointNum++;
    return (tmp);   
}

Fixed& Fixed::operator--(void) {
    
    this->_fixedPointNum--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    
    Fixed tmp = *this;
    this->_fixedPointNum--;
    return (tmp);   
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {

    if(obj1.getRawBits() < obj2.getRawBits())
        return (obj1);
    return (obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {

    if(obj1.getRawBits() > obj2.getRawBits())
        return (obj1);
    return (obj2);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {

    if(obj1.getRawBits() < obj2.getRawBits())
        return (obj1);
    return (obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {

    if(obj1.getRawBits() < obj2.getRawBits())
        return (obj1);
    return (obj2);
}

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed) {

    COUT << fixed.toFloat();
    return (COUT);
}