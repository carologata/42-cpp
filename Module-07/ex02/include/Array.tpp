#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : _array(new T[copy._size]), _size(copy._size)
{
    for (int i = 0; i < _size; i++)
    {
        _array[i] = copy._array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
        delete[] _array;
        _array = new T[copy._size];
        _size = copy._size;
        for (int i = 0; i < _size; i++)
        {
            _array[i] = copy._array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] _array;
}

template <typename T>
T& Array<T>::operator[](int index) throw(std::out_of_range) // specify exceptions that a function might throw 
{
    if (index < 0 || index >= _size)
        throw std::out_of_range("Index out of range");
    return _array[index];
}

template <typename T>
int Array<T>::size(void) const
{
    return _size;
}

#endif