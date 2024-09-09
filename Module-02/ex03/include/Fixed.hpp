#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

public:

    Fixed(void);
    Fixed(const int     intNum);
    Fixed(const float   floatNum);
    Fixed(const Fixed& copy);
    Fixed&  operator=(const Fixed& copy);
    ~Fixed(void);

    int             getRawBits(void) const;
    void            setRawBits(int const raw);

    float           toFloat(void) const;
    int             toInt(void) const;

    bool            operator>(const Fixed& compareObj);
    bool            operator<(const Fixed& compareObj);
    bool            operator>=(const Fixed& compareObj);
    bool            operator<=(const Fixed& compareObj);
    bool            operator==(const Fixed& compareObj);
    bool            operator!=(const Fixed& compareObj);

    Fixed           operator+(const Fixed& arithmeticObj);
    Fixed           operator-(const Fixed& arithmeticObj);
    Fixed           operator*(const Fixed& arithmeticObj);
    Fixed           operator/(const Fixed& arithmeticObj);

    Fixed&          operator++(void);
    Fixed           operator++(int);
    Fixed&          operator--(void);
    Fixed           operator--(int);

    static const Fixed&    min(const Fixed& obj1, const Fixed& obj2);
    static const Fixed&    max(const Fixed& obj1, const Fixed& obj2);
    static Fixed&          min(Fixed& obj1, Fixed& obj2);
    static Fixed&          max(Fixed& obj1, Fixed& obj2);

private:

    int              fixedPointNum;
    static const int fractionalBits;

};

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed);

#endif