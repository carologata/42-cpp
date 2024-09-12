#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {

public:

    Fixed(void);
    Fixed(const int     intNum);
    Fixed(const float   floatNum);
    ~Fixed(void);
    Fixed(const Fixed& copy);
    Fixed&  operator=(const Fixed& copy);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    float   toFloat(void) const;
    int     toInt(void) const;

private:

    int              _fixedPointNum;
    static const int _fractionalBits;
};

std::ostream& operator<<(std::ostream& COUT, const Fixed& fixed);

#endif