#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{

public:
    
    Array(void);
    Array(unsigned int n);
    Array(const Array& copy);
    Array& operator=(const Array& copy);
    ~Array(void);

    T&  operator[](int index) throw(std::out_of_range);
    int size(void) const;

private:

    T   *_array;
    int _size;
};

#endif