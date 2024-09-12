#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:

    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed& copy);
    Fixed&  operator=(const Fixed& copy);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

private:

    int              _fixedPointNum;
    static const int _fractionalBits;
};

#endif