#ifndef FIXED_H
#define FIXED_H

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

    int              fixedPointNum;
    static const int fractionalBits;
};

#endif